#ifndef KHUTILS_XML_PROCESS_HPP_INC
#define KHUTILS_XML_PROCESS_HPP_INC

#include <functional>

#if defined(KHUTILS_XMLPROCESS_USE_ZENXML)
#include <zenxml/parser.h>
#endif	// defined(KHUTILS_XMLPROCESS_USE_ZPROCESS)

#if defined(KHUTILS_XMLPROCESS_USE_TINIXML2)
#include <tinyxml2.h>
#endif	// defined(KHUTILS_XMLPROCESS_USE_TINIXML2)


namespace khutils
{
#if defined(KHUTILS_XMLPROCESS_USE_ZPROCESS)
	typedef std::function<void(const zen::XmlElement& elem)> ElementProcessor;
	void recurseXmlTree(const zen::XmlElement& elem, ElementProcessor);
#endif	// defined(KHUTILS_XMLPROCESS_USE_ZPROCESS)

#if defined(KHUTILS_XMLPROCESS_USE_TINIXML2)
	typedef std::function<void(const tinyxml2::XMLElement* elem)> ElementProcessor;
	void recurseXmlTree(const tinyxml2::XMLElement* elem, ElementProcessor);
#endif	// defined(KHUTILS_XMLPROCESS_USE_TINIXML2)


}	// namespace khutils

#if defined(KHUTILS_XMLPROCESS_IMPL)

namespace khutils
{
#if defined(KHUTILS_XMLPROCESS_USE_ZPROCESS)
	void recurseXmlTree(const zen::XmlElement& elem, ElementProcessor process)
	{
		process(elem);

		auto children = elem.getChildren();
		for (auto it = children.first; it != children.second; ++it)
		{
			recurseXmlTree(*it, process);
		}
	}
#endif	// defined(KHUTILS_XMLPROCESS_USE_ZPROCESS)

#if defined(KHUTILS_XMLPROCESS_USE_TINIXML2)

	void recurseXmlTree(const tinyxml2::XMLElement* elem, ElementProcessor process)
	{
		process(elem);

		auto child = elem->FirstChildElement();
		while (child)
		{
			recurseXmlTree(child, process);

			if (child == elem->LastChildElement())
				break;

			child = child->NextSiblingElement();
		}
	}
#endif	// defined(KHUTILS_XMLPROCESS_USE_TINIXML2)

}	// namespace khutils

#endif	// defined(KHUTILS_XMLPROCESS_IMPL)

#endif	// !KHUTILS_XML_PROCESS_HPP_INC