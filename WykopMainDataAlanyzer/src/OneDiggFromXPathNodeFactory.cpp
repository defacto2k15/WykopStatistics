//
// Created by defacto on 14.09.15.
//

#include "OneDiggFromXPathNodeFactory.h"
#include "boost/algorithm/string/split.hpp"
#include <boost/algorithm/string.hpp>
#include <constantElements/InputFileConstants.h>

OneDigg OneDiggFromXPathNodeFactory::createDigg(pugi::xpath_node &node) {
	ValuesFromNodeExtractor extractor;
	auto title = extractor.getValueFromNode(node, (InputFileConstants::getDiggNameNodeName()+"/text()").c_str());
	auto description = extractor.getValueFromNode(node, (InputFileConstants::getDiggDescriptionNodeName()+"/text()").c_str());
	int diggsCount = getDiggsCount(node, extractor);

	std::string date = fetchDate(node, extractor);
	std::string time = fetchTime(node, extractor);
	std::string dateWithTime = extractor.getValueFromNode(node, (InputFileConstants::getDiggTimeNodeName()+"/text()").c_str());
	return OneDigg(title, description, diggsCount, date, dateWithTime);
}

int OneDiggFromXPathNodeFactory::getDiggsCount(const pugi::xpath_node &node, ValuesFromNodeExtractor &extractor) const {
	auto diggsCountAsString = extractor.getValueFromNode(node, (InputFileConstants::getDiggCountNodeName()+"/text()").c_str());
	int diggsCount;
	try {
		diggsCount = stoi(diggsCountAsString);
	} catch (std::invalid_argument a){
		diggsCount = 0;
	}
	return diggsCount;
}

std::string OneDiggFromXPathNodeFactory::fetchDate(const pugi::xpath_node &node, ValuesFromNodeExtractor &extractor) const {
	auto dateWithHour = extractor.getValueFromNode(node, (InputFileConstants::getDiggTimeNodeName()+"/text()").c_str());
	std::stringstream ss;
	ss << dateWithHour;
	std::string date;
	ss >> date;
	return date;
}

std::string OneDiggFromXPathNodeFactory::fetchTime(pugi::xpath_node &node, ValuesFromNodeExtractor extractor) {
	auto dateWithHour = extractor.getValueFromNode(node, (InputFileConstants::getDiggTimeNodeName()+"/text()").c_str());
	std::stringstream ss;
	ss << dateWithHour;
	std::string date;
	ss >> date;
	std::string time;
	ss >> time;
	return time;
}
