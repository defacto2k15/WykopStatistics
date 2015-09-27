//
// Created by defacto on 24.09.15.
//

#include <constantElements/InputFileConstants.h>
#include <iomanip>
#include <iostream>
#include "InputXmlCreator.h"
#include "test/help/Random.h"

InputXmlCreator &InputXmlCreator::createDiggsWithRandomInfo() {
	this->doc.append_child(InputFileConstants::getRootNodeName().c_str());
	return *this;
}

pugi::xml_node InputXmlCreator::getRootNode() {
	return this->doc.child(InputFileConstants::getRootNodeName().c_str());
}

pugi::xml_node InputXmlCreator::addRandomDataToDigg(pugi::xml_node node) {
	addValueNode(node, InputFileConstants::getDiggNameNodeName(), test::Random::CreateRandomAlphanumericString());
	addValueNode(node, InputFileConstants::getDiggTimeNodeName(), test::Random::CreateRandomAlphanumericString());
	addValueNode(node, InputFileConstants::getDiggCountNodeName(), createRandomDiggsNumber());
	addValueNode(node, InputFileConstants::getDiggDescriptionNodeName(), test::Random::CreateRandomAlphanumericString());
	return node;
}

void InputXmlCreator::setDate(pugi::xml_node &node, const DayName time) {
	std::stringstream ss;
	ss << time << " " << createRandomHourString();
	node.child(InputFileConstants::getDiggTimeNodeName().c_str()).first_child().set_value(ss.str().c_str());
}

std::string InputXmlCreator::createRandomHourString(){
	std::stringstream output;
	std::stringstream ss;
	ss << std::setfill('0') <<std::setw(2) << (test::Random::CreateRandomInt() % 24);
	output << ss.str()<<":";
	ss.str("");
	ss << std::setfill('0') <<std::setw(2) << (test::Random::CreateRandomInt()%60);
	output << ss.str()<<":";
	ss.str("");
	ss << std::setfill('0') <<std::setw(2) << (test::Random::CreateRandomInt()%60);

	output << ss.str();
	return output.str();
}

pugi::xml_node InputXmlCreator::addDiggToXmlDoc(const char *nodeName) {
	return getRootNode().append_child(nodeName);
}

InputXmlCreator & InputXmlCreator::AmountByDays(std::map<DayName, int> &amountByDatesMap) {
	this->amountByDatesMap_ = amountByDatesMap;
	return *this;
}

void InputXmlCreator::Create(){
	for(auto it = amountByDatesMap_.begin(); it != amountByDatesMap_.end(); it++){
		for( int i = 0; i != it->second; i++){
			auto diggNode = addDiggToXmlDoc(InputFileConstants::getDiggNodeName().c_str());
			addRandomDataToDigg(diggNode);
			setDate(diggNode, it->first);
		}
	}
}

void InputXmlCreator::writeToFile(const char *filePath) {
	doc.save_file(filePath);
}

void InputXmlCreator::addValueNode(pugi::xml_node node, std::string nodeName, std::string nodeValue) {
	auto newNode = node.append_child(nodeName.c_str());
	newNode.append_child(pugi::node_pcdata).set_value(nodeValue.c_str());
}

InputXmlCreator &InputXmlCreator::WithMinimialDiggsNumber(int minimalDiggsNumber) {
	this->minimalDiggsNumber_ = minimalDiggsNumber;
	return *this;
}

std::string InputXmlCreator::createRandomDiggsNumber() {
	return std::to_string( test::Random::CreateRandomInt(this->minimalDiggsNumber_, 1000));
}
