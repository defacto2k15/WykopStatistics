//
// Created by defacto on 24.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_INPUTXMLCREATOR_H
#define WYKOPMAINDATAALANYZER_INPUTXMLCREATOR_H


#include <pugixml.hpp>
#include <CommonTypes.h>
#include <map>

class InputXmlCreator {
	pugi::xml_document doc;
	int minimalDiggsNumber_ = 0;
	std::map<DayName, int> amountByDatesMap_;
public:
	InputXmlCreator()= default;
	InputXmlCreator &createDiggsWithRandomInfo();
	InputXmlCreator &AmountByDays(std::map<DayName, int> &amountByDatesMap);
	InputXmlCreator &WithMinimialDiggsNumber(int minimalDiggsNumber);
	void Create();
	void writeToFile(const char *filePath);

private:
	pugi::xml_node getRootNode();
	pugi::xml_node addRandomDataToDigg(pugi::xml_node node);

	void setDate(pugi::xml_node &node, const DayName time);
	pugi::xml_node addDiggToXmlDoc(const char *node);

	void addValueNode(pugi::xml_node node, std::string nodeName, std::string nodeValue);

	std::string createRandomHourString();

	std::string createRandomDiggsNumber();
};


#endif //WYKOPMAINDATAALANYZER_INPUTXMLCREATOR_H
