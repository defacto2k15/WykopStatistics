//
// Created by defacto on 24.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_INPUTXMLCREATOR_H
#define WYKOPMAINDATAALANYZER_INPUTXMLCREATOR_H


#include <pugixml.hpp>
#include <CommonTypes.h>
#include <map>
#include <vector>
#include "OneDigg.h"

class InputXmlCreator {
	pugi::xml_document doc;
	std::map<DayName, int> amountByDatesMap_;
public:
	InputXmlCreator()= default;

	void writeToFile(const char *filePath);

	void createWithDiggs(std::vector<OneDigg> diggsVector);

private:
	pugi::xml_node addDiggToXmlDoc(const char *node);

	void addValueNode(pugi::xml_node &node, std::string nodeName, std::string nodeValue);

	void fillNodeWithData(pugi::xml_node &node, OneDigg &digg);

	void addRootNode();

	pugi::xml_node getRootNode();
};


#endif //WYKOPMAINDATAALANYZER_INPUTXMLCREATOR_H
