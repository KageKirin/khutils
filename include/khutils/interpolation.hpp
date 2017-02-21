#ifndef KHUTILS_INTERPOLATION_HPP_INC
#define KHUTILS_INTERPOLATION_HPP_INC

#include <boost/container/flat_map.hpp>

namespace khutils
{

	//////////////////////////////////////////////////////////////////////////
	//- structures used for interpolation

	template <typename K, typename T>
	struct BaseInterpolation
	{
		typedef K key_type;
		typedef T value_type;
		typedef boost::container::flat_map<K, T> key_value_map;	// bonus feature: keys are sorted

		key_value_map m_keyValueMap;

		BaseInterpolation(const key_value_map& kvm);

		virtual ~BaseInterpolation();

		virtual value_type get(const key_type& key) const = 0;
	};

	//////////////////////////////////////////////////////////////////////////
	//- implementations

	template <typename K, typename T>
	struct FixStepInterpolation : BaseInterpolation<K, T>
	{
		typedef BaseInterpolation<K, T> parent_type;
		typedef typename parent_type::key_type		key_type;
		typedef typename parent_type::value_type	value_type;
		typedef typename parent_type::key_value_map key_value_map;

		FixStepInterpolation(const key_value_map& kvm);

		virtual value_type get(const key_type& key) const;
	};


	template <typename K, typename T>
	struct LinearInterpolation : BaseInterpolation<K, T>
	{
		typedef BaseInterpolation<K, T> parent_type;
		typedef typename parent_type::key_type		key_type;
		typedef typename parent_type::value_type	value_type;
		typedef typename parent_type::key_value_map key_value_map;
		typedef typename key_value_map::value_type  key_value_pair;

		LinearInterpolation(const key_value_map& kvm);

		virtual value_type get(const key_type& key) const;

	protected:
		virtual value_type get_interpolated(const key_value_pair& lower, const key_value_pair& upper, const key_type& t) const;
	};


	template <typename K, typename T>
	struct CatmullRomSplineInterpolation : LinearInterpolation<K, T>
	{
		typedef LinearInterpolation<K, T> parent_type;
		typedef typename parent_type::key_type		key_type;
		typedef typename parent_type::value_type	value_type;
		typedef typename parent_type::key_value_map key_value_map;
		typedef typename key_value_map::value_type  key_value_pair;

		key_value_map _tangents;

		CatmullRomSplineInterpolation(const key_value_map& kvm);

		virtual value_type get(const key_type& key) const;

	protected:
		virtual value_type get_interpolated(const key_value_pair& lower, const key_value_pair& upper, const key_type& t) const;
	};

}	// namespace khutils

#if defined(KHUTILS_INTERPOLATION_INLINE)

#include "khutils/assertion.hpp"
#include <numeric>

namespace khutils
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//! IMPORTANT: this->m_keyValueMap fixes "Use of undeclared identifier 'm_keyValueMap'" compiler error
	//! due to two-phase name lookup
	//! DO NOT REMOVE this-> in templates below!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	//! explicit copy of iterators
	template <typename T>
	T explicit_copy(T input)
	{
		return input;
	}

	//////////////////////////////////////////////////////////////////////////
	//- base class

	template <typename K, typename T>
	BaseInterpolation<K, T>::BaseInterpolation(const key_value_map& kvm) : m_keyValueMap(kvm)
	{
		KHUTILS_ASSERT(!m_keyValueMap.empty());
	}


	template <typename K, typename T>
	BaseInterpolation<K, T>::~BaseInterpolation()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	//- fix step interpolation implementation

	template <typename K, typename T>
	FixStepInterpolation<K, T>::FixStepInterpolation(const key_value_map& kvm) : parent_type(kvm)
	{
	}

	template <typename K, typename T>
	typename FixStepInterpolation<K, T>::value_type FixStepInterpolation<K, T>::get(const key_type& key) const
	{
		if (this->m_keyValueMap.size() == 1)
			return this->m_keyValueMap.at(0);

		auto& lower = this->m_keyValueMap.lower_bound(key);


		if (lower == this->m_keyValueMap.end() ||	// if beyond upper side of range, return last key (end()-1) value
			(key < lower->first && std::distance(this->m_keyValueMap.begin(), lower) > 0))	// if after first key,
																							  // return value from
																							  // exact previous key
		{
			lower--;
		}

		khutils::check_NaN(lower->second);

		return lower->second;
	}

	//////////////////////////////////////////////////////////////////////////
	//- linear interpolation implementation

	template <typename K, typename T>
	LinearInterpolation<K, T>::LinearInterpolation(const key_value_map& kvm) : parent_type(kvm)
	{
	}

	template <typename K, typename T>
	typename LinearInterpolation<K, T>::value_type LinearInterpolation<K, T>::get(const key_type& key) const
	{
		// if only one element, return that value
		if (this->m_keyValueMap.size() == 1)
			return this->m_keyValueMap.at(0);

		// if key value exact match, return the value
		typename key_value_map::const_iterator atkey = this->m_keyValueMap.find(key);
		if (atkey != this->m_keyValueMap.end())
			return atkey->second;


		typename key_value_map::const_iterator lower = this->m_keyValueMap.lower_bound(key);
		typename key_value_map::const_iterator upper = this->m_keyValueMap.upper_bound(key);


		// if beyond upper side of range, return last available key's (end()-1) value
		if (lower == this->m_keyValueMap.end())
		{
			lower--;
			return lower->second;
		}

		// if after first key, create range from lower key to this key
		if ((std::distance(this->m_keyValueMap.begin(), lower) > 0))
		{
			upper = explicit_copy(lower);
			lower--;
		}

		KHUTILS_ASSERT(lower->first < key);
		KHUTILS_ASSERT(upper->first > key);

		typename key_value_map::value_type lower_kv = *lower;
		typename key_value_map::value_type upper_kv = *upper;

		key_type end = upper_kv.first - lower_kv.first;
		KHUTILS_ASSERT(end != 0);

		key_type   inter = key - lower_kv.first;
		value_type t	 = value_type(inter) / value_type(end);

		return get_interpolated(lower_kv, upper_kv, t);
	}

	template <typename K, typename T>
	typename LinearInterpolation<K, T>::value_type LinearInterpolation<K, T>::get_interpolated(const key_value_pair& lower,
																							   const key_value_pair& upper,
																							   const key_type& t) const
	{
		value_type r = (1 - t) * lower.second + t * upper.second;

		khutils::check_NaN(r);
		return r;
	}


	//////////////////////////////////////////////////////////////////////////
	//- catmull-rom spline interpolation implementation

	template <typename K, typename T>
	CatmullRomSplineInterpolation<K, T>::CatmullRomSplineInterpolation(const key_value_map& kvm) : parent_type(kvm)
	{
		// create start/end points
		if (this->m_keyValueMap.size() > 1)
		{
			const auto first_kvp_it = this->m_keyValueMap.begin();
			const auto last_kvp_it  = --explicit_copy(this->m_keyValueMap.end());

			const auto second_kvp_it		 = ++explicit_copy(first_kvp_it);
			const auto second_to_last_kvp_it = --explicit_copy(last_kvp_it);

			// extrapolating for virtual -1th and n+1th knots
			const typename key_value_map::value_type firstminus1_kvp(2 * first_kvp_it->first - second_kvp_it->first,
																	 2 * first_kvp_it->second - second_kvp_it->second);

			const typename key_value_map::value_type lastplus1_kvp(2 * last_kvp_it->first - second_to_last_kvp_it->first,
																   2 * last_kvp_it->second - second_to_last_kvp_it->second);

			// computing tangents
			// all the magic of a catmull-rom spline in 1 lambda below
			auto compute_tangent
			  = [](const typename key_value_map::value_type& prev, const typename key_value_map::value_type& next) -> value_type {
				return (next.second - prev.second) / value_type(next.first - prev.first);
			};

			// first and last tangents
			_tangents[first_kvp_it->first] = compute_tangent(firstminus1_kvp, *second_kvp_it);
			_tangents[last_kvp_it->first]  = compute_tangent(*second_to_last_kvp_it, lastplus1_kvp);

			// the rest
			for (auto it = second_kvp_it; it != last_kvp_it; ++it)
			{
				const auto next		 = ++explicit_copy(it);
				const auto prev		 = --explicit_copy(it);
				_tangents[it->first] = compute_tangent(*prev, *next);
			}
		}
	}

	template <typename K, typename T>
	typename CatmullRomSplineInterpolation<K, T>::value_type CatmullRomSplineInterpolation<K, T>::get(const key_type& key) const
	{
		return parent_type::get(key);
	}

	template <typename K, typename T>
	typename CatmullRomSplineInterpolation<K, T>::value_type CatmullRomSplineInterpolation<K, T>::get_interpolated(
	  const key_value_pair& lower, const key_value_pair& upper, const key_type& t) const
	{
		auto h00 = [](value_type x) -> value_type { return value_type(2) * x * x * x - value_type(3) * x * x + 1; };
		auto h10 = [](value_type x) -> value_type { return x * x * x - value_type(2) * x * x + x; };
		auto h01 = [](value_type x) -> value_type { return -value_type(2) * x * x * x + value_type(3) * x * x; };
		auto h11 = [](value_type x) -> value_type { return x * x * x - x * x; };

		khutils::check_NaN(h00(t));
		khutils::check_NaN(h10(t));
		khutils::check_NaN(h01(t));
		khutils::check_NaN(h11(t));

		auto r = h00(t) * lower.second					 //
				 + h10(t) * _tangents.at(lower.first)	//
				 + h01(t) * upper.second				 //
				 + h11(t) * _tangents.at(upper.first);

		khutils::check_NaN(r);
		return r;
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined(KHUTILS_INTERPOLATION_INLINE)

#endif	// !KHUTILS_INTERPOLATION_HPP_INC
