#ifndef KHUTILS_RUNTIME_EXCEPTIONS_HPP_INC
#define KHUTILS_RUNTIME_EXCEPTIONS_HPP_INC

#include <stdexcept>

namespace khutils
{
	class FatalImportException : public std::runtime_error
	{
	public:
		explicit FatalImportException(const std::string& pErrorText);
	};

	class FatalExportException : public std::runtime_error
	{
	public:
		explicit FatalExportException(const std::string& pErrorText);
	};

	class SpiritualCastException : public std::runtime_error
	{
	public:
		explicit SpiritualCastException(const std::string& pErrorText);
	};

	class MissingImplementationException : public std::runtime_error
	{
	public:
		explicit MissingImplementationException(const std::string& pErrorText);
	};

}	// namespace khutils

#if defined(KHUTILS_RUNTIME_EXCEPTIONS_IMPL)

#include "khutils/runtime_exceptions.hpp"

namespace khutils
{

	//////////////////////////////////////////////////////////////////////////

	FatalImportException::FatalImportException(const std::string& pErrorText) : std::runtime_error(pErrorText)
	{
	}

	FatalExportException::FatalExportException(const std::string& pErrorText) : std::runtime_error(pErrorText)
	{
	}

	SpiritualCastException::SpiritualCastException(const std::string& pErrorText) : std::runtime_error(pErrorText)
	{
	}


	MissingImplementationException::MissingImplementationException(const std::string& pErrorText)
		: std::runtime_error(pErrorText)
	{
	}


}	// namespace khutils

//////////////////////////////////////////////////////////////////////////

#endif	// defined (KHUTILS_RUNTIME_EXCEPTIONS_IMPL)

#endif	// !KHUTILS_RUNTIME_EXCEPTIONS_HPP_INC
