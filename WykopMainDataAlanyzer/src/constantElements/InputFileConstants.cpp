//
// Created by defacto on 24.09.15.
//

#include "InputFileConstants.h"

std::string InputFileConstants::getRootNodeName() {
	return std::string(rootNodeName);
}

std::string InputFileConstants::getDiggNodeName() {
	return std::string(diggNodeName);
}

std::string InputFileConstants::getPathToDiggNodes() {
	std::stringstream ss;
	ss << getRootNodeName() << "/" << getDiggNodeName();
	return ss.str();
}