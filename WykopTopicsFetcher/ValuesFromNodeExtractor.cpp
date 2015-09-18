//
// Created by defacto on 08.09.15.
//

#include "pugixml.hpp"
#include "ValuesFromNodeExtractor.h"

const std::string ValuesFromNodeExtractor::getValueFromNode(const pugi::xpath_node node, const char *xPathToValue) {
    pugi::xpath_query queryToValue(xPathToValue);
    pugi::xpath_node_set foundNodes = queryToValue.evaluate_node_set(node);
    auto nodeVal = foundNodes.first().node().value();
    return nodeVal;
}

const std::string ValuesFromNodeExtractor::getAttributeFromNode(const pugi::xpath_node node, const char *xPathToValue) {
    pugi::xpath_query queryToValue(xPathToValue);
    pugi::xpath_node_set foundNodes = queryToValue.evaluate_node_set(node);
    auto attrVal = foundNodes.first().attribute().value();
    return attrVal;
}