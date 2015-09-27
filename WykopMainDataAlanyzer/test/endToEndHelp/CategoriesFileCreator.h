//
// Created by defacto on 23.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_CATEGORIESFILECREATOR_H
#define WYKOPMAINDATAALANYZER_CATEGORIESFILECREATOR_H

#include <string>
#include <pugixml.hpp>
#include <constantElements/CharacteristicFileConstants.h>

class CategoriesFileCreator {
private:
	pugi::xml_document doc;
	pugi::xml_node rootNode;
public:
	CategoriesFileCreator();

	void addAllCategory(std::string categoryName);

	void writeToFile(const char *filePath);
};


#endif //WYKOPMAINDATAALANYZER_CATEGORIESFILECREATOR_H
