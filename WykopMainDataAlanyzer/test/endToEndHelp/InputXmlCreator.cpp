//
// Created by defacto on 24.09.15.
//

#include <constantElements/InputFileConstants.h>
#include <iomanip>
#include <iostream>
#include <OneDigg.h>
#include "InputXmlCreator.h"
#include "test/help/Random.h"

pugi::xml_node InputXmlCreator::addDiggToXmlDoc(const char *nodeName) {
	return getRootNode().append_child(nodeName);
}

pugi::xml_node InputXmlCreator::getRootNode() {
	return this->doc.child(InputFileConstants::getRootNodeName().c_str());
}

void InputXmlCreator::writeToFile(const char *filePath) {
	doc.save_file(filePath);
}

void InputXmlCreator::addValueNode(pugi::xml_node &node, std::string nodeName, std::string nodeValue) {
	auto newNode = node.append_child(nodeName.c_str());
	newNode.append_child(pugi::node_pcdata).set_value(nodeValue.c_str());
}


void InputXmlCreator::createWithDiggs(std::vector<OneDigg> diggsVector) {
	addRootNode();
	for( auto &digg : diggsVector){
		auto diggXmlNode = addDiggToXmlDoc(InputFileConstants::getDiggNodeName().c_str());
		fillNodeWithData(diggXmlNode, digg);
	}
}

void InputXmlCreator::fillNodeWithData(pugi::xml_node &node, OneDigg &digg) {
	addValueNode(node, InputFileConstants::getDiggNameNodeName(), digg.getTitle());
	addValueNode(node, InputFileConstants::getDiggTimeNodeName(), digg.getAddDateWithTime());
	addValueNode(node, InputFileConstants::getDiggCountNodeName(), std::to_string(digg.getDiggCount()));
	addValueNode(node, InputFileConstants::getDiggDescriptionNodeName(), digg.getDescription());
}

void InputXmlCreator::addRootNode() {
	this->doc.append_child(InputFileConstants::getRootNodeName().c_str());
}
