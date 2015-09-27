//
// Created by defacto on 23.09.15.
//

#include <stdexcept>
#include <sstream>
#include "CategoriesFileCreator.h"

void CategoriesFileCreator::addAllCategory(std::string categoryName) {
	auto newCategoryNode = this->rootNode.append_child(CharacteristicFileConstants::getCategoryNodeName().c_str());
	auto nameNode = newCategoryNode.append_child(CharacteristicFileConstants::getCategoryNameNodeName().c_str());
	nameNode.append_child(pugi::node_pcdata).set_value(categoryName.c_str());
}

void CategoriesFileCreator::writeToFile(const char *filePath) {
	auto saveResult = doc.save_file(filePath);
	if( saveResult == false){
		stringstream ss;
		ss << "Saving Categories xml to file of path " << filePath << "failed";
		throw runtime_error(ss.str());
	}
}

CategoriesFileCreator::CategoriesFileCreator() {
	rootNode = doc.append_child(CharacteristicFileConstants::getRootNodeName().c_str());
}