#ifndef KHUTILS_XML2JSON_HPP_INC
#define KHUTILS_XML2JSON_HPP_INC

#include <string>

#if defined(KHUTILS_XML2JSON_USE_ZENXML)
#include <zenxml/parser.h>
#endif	// defined(KHUTILS_XML2JSON_USE_ZENXML)

#if defined(KHUTILS_XML2JSON_USE_TINIXML2)
#include <tinyxml2.h>
#endif	// defined(KHUTILS_XML2JSON_USE_TINIXML2)


namespace khutils
{
	struct X2JOptions
	{
		std::string attributePrefix;
		std::string cdataPrefix;
		std::string elementPrefix;
	};

	std::string xml_to_json(const std::string&, const X2JOptions&);
	void		xml_to_json(const std::string&, std::ostream&, const X2JOptions&);
}	// namespace khutils

#if defined(KHUTILS_XML2JSON_IMPL)


#if defined(KHUTILS_XML2JSON_USE_ZENXML)
#include <zenxml/parser.h>
#define KHUTILS_XMLPROCESS_USE_ZENXML
#endif	// defined(KHUTILS_XML2JSON_USE_ZENXML)

#if defined(KHUTILS_XML2JSON_USE_TINIXML2)
#include <tinyxml2.h>
#define KHUTILS_XMLPROCESS_USE_TINIXML2
#endif	// defined(KHUTILS_XML2JSON_USE_TINIXML2)

#include "xmlprocess.hpp"

#include <algorithm>
#include <iostream>

#include <string>
#include <stringstream>

namespace khutils
{
	namespace x2j_details
	{
#if defined(KHUTILS_XML2JSON_USE_ZENXML)
		void processToJson(const zen::XmlElement& elem, std::ostream& outs, const X2JOptions& opts);
#endif	// defined(KHUTILS_XML2JSON_USE_ZENXML)

#if defined(KHUTILS_XML2JSON_USE_TINIXML2)
		void processToJson(const tinyxml2::XMLElement* elem, std::ostream& outs, const X2JOptions& opts);
#endif	// defined(KHUTILS_XML2JSON_USE_TINIXML2)
	}	 // x2j_details

	std::string xml_to_json(const std::string& xmlString, const X2JOptions& opts)
	{
		std::ostringstream oss;
		xml_to_json(xmlString, oss, opts);
		return oss.str();
	}


	void xml_to_json(const std::string& xmlString, std::ostream& oss, const X2JOptions& opts)
	{
#if defined(KHUTILS_XML2JSON_USE_ZENXML)
		auto doc = zen::parse(xmlString);
		recurseXmlTree(doc.root(), [&oss, &opts](auto& elem) { x2j_details::processToJson(elem, oss, opts); });
#endif	// defined(KHUTILS_XML2JSON_USE_ZENXML)

#if defined(KHUTILS_XML2JSON_USE_TINIXML2)
		tinyxml2::XMLDocument x2doc;
		auto				  x2err = x2doc.Parse(xmlString.c_str());
		recurseXmlTree(x2doc.GetRoot(), [&oss, &opts](auto elem) { x2j_details::processToJson(elem, oss, opts); });
#endif	// defined(KHUTILS_XML2JSON_USE_TINIXML2)
	}


	namespace x2j_details
	{
		constexpr char opbracket[] = "{ ";
		constexpr char clbracket[] = " }";
		constexpr char highcomma[] = "\"";
		constexpr char colon[]	 = ": ";
		constexpr char comma[]	 = ", ";

#if defined(KHUTILS_XML2JSON_USE_ZENXML)
		void processToJson(const zen::XmlElement& elem, std::ostream& outs, const X2JOptions& opts)
		{
			outs << highcomma << opts.elementPrefix << elem.GetNameAs<std::string>() << highcomma << colon;
			outs << opbracket;

			auto atts = elem.getAttributes();
			for (auto it = atts.first; it != atts.second; ++it)
			{
				outs << highcomma << opts.attributePrefix << it->first << highcomma << colon << highcomma << it->second << highcomma;
				if ((it + 1) != atts.second)
					outs << comma;
			}

			std::string value;
			auto		valueOk = elem.getValue(elem, value);
			if (valueOk)
			{
				outs << value;
			}

			outs << clbracket;
		}
#endif	// defined(KHUTILS_XML2JSON_USE_ZENXML)

#if defined(KHUTILS_XML2JSON_USE_TINIXML2)
		void processToJson(const tinyxml2::XMLElement* elem, std::ostream& outs, const X2JOptions& opts)
		{
		}
#endif	// defined(KHUTILS_XML2JSON_USE_TINIXML2)
	}	 // x2j_details


}	// namespace khutils

#endif	// defined(KHUTILS_XML2JSON_IMPL)

#endif	// !KHUTILS_XML2JSON_HPP_INC