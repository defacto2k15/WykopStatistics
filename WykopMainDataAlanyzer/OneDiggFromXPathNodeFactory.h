//
// Created by defacto on 14.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_ONEDIGGFROMXPATHNODEFACTORY_H
#define WYKOPMAINDATAALANYZER_ONEDIGGFROMXPATHNODEFACTORY_H


#include "OneDigg.h"
#include "pugixml.hpp"
#include "ValuesFromNodeExtractor.h"

class OneDiggFromXPathNodeFactory {
public:
	OneDigg createDigg(pugi::xpath_node &node);


	std::string fetchDate(const pugi::xpath_node &node, ValuesFromNodeExtractor &extractor) const;

	int getDiggsCount(const pugi::xpath_node &node, ValuesFromNodeExtractor &extractor) const;
};


#endif //WYKOPMAINDATAALANYZER_ONEDIGGFROMXPATHNODEFACTORY_H
