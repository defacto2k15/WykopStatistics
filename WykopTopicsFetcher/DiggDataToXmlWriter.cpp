//
// Created by defacto on 08.09.15.
//

#include "DiggDataToXmlWriter.h"
#include "pugixml.hpp"

DiggDataToXmlWriter::DiggDataToXmlWriter(const char *pathToXmlFile) {
    this->xmlFileStream.open(pathToXmlFile);
    this->rootNode = this->xmlDoc.append_child("RootDiggs");
}

void DiggDataToXmlWriter::addOneDiggData(DiggData digg) {
    pugi::xml_node oneDiggNode = rootNode.append_child("OneDigg");
    this->addTextNode(oneDiggNode, "title", digg.getDiggTitle());
    this->addTextNode(oneDiggNode, "link", digg.getDiggLink());
    this->addTextNode(oneDiggNode, "commentCount", digg.getDiggCommentsCount() );
    this->addTextNode(oneDiggNode, "diggCount", digg.getDiggCount() );
    this->addTextNode(oneDiggNode, "time", digg.getDiggTime() );
    this->addTextNode(oneDiggNode, "description", digg.getDiggDescription());
}

void DiggDataToXmlWriter::addTextNode(pugi::xml_node node, const char *nodeName, const std::string textNodeValue) {
    pugi::xml_node newNode = node.append_child(nodeName);
    newNode.append_child(pugi::node_pcdata).set_value(textNodeValue.c_str());
}

void DiggDataToXmlWriter::saveXmlToFile() {
    this->xmlDoc.save(this->xmlFileStream);
}

DiggDataToXmlWriter::~DiggDataToXmlWriter() { xmlFileStream.close(); }