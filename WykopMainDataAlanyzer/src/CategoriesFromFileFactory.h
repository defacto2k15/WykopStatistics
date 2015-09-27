//
// Created by defacto on 16.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_CATEGORIESFROMFILEFACTORY_H
#define WYKOPMAINDATAALANYZER_CATEGORIESFROMFILEFACTORY_H

#include <vector>
#include <bits/unique_ptr.h>
#include <bits/stl_bvector.h>
#include "pugixml.hpp"
#include "TopicCategory.h"
#include "NodesFromXmlFileFetcher.h"
#include "ValuesFromNodeExtractor.h"
#include "TopicCategoryWithLambda.h"
#include "TopicCategoryWithKeywords.h"
#include <memory>
#include <boost/algorithm/string.hpp>
#include <constantElements/CharacteristicFileConstants.h>

class CategoriesFromFileFactory {
	std::unique_ptr<pugi::xml_document> categoriesDoc;
public:

	CategoriesFromFileFactory(std::unique_ptr <pugi::xml_document> categoriesDocument)
			: categoriesDoc( std::move (categoriesDocument)){}

	std::vector<std::shared_ptr<TopicCategory>> getCategories(){
		std::vector<std::shared_ptr<TopicCategory>> outVec;

		NodesFromXmlFileFetcher fetcher(std::move(categoriesDoc));
		std::vector<pugi::xpath_node> nodes = fetcher.fetchNodes((
				CharacteristicFileConstants::getRootNodeName() + "/" +
				CharacteristicFileConstants::getCategoryNodeName()).c_str());

		for( auto &oneCategoryNode : nodes){
			outVec.push_back(CreateOneCategory(oneCategoryNode));
		}
		return outVec;
	}
private:
	std::shared_ptr<TopicCategory> CreateOneCategory(const pugi::xpath_node oneCategoryNode) const {
		ValuesFromNodeExtractor extractor;
		auto categoryName = extractor.getValueFromNode(oneCategoryNode, (CharacteristicFileConstants::getCategoryNameNodeName()+"/text()").c_str());
		boost::algorithm::trim(categoryName);
		auto keywordsAsOneString = extractor.getValueFromNode(oneCategoryNode, (CharacteristicFileConstants::getCategoryKeywordsNodeName()+"/text()").c_str());
		if(  keywordsAsOneString == ""){
			return std::shared_ptr<TopicCategory>( new TopicCategoryWithLambda([](OneDigg& ){return true;}, categoryName ));
		} else {
			std::vector<std::string> keywordsVec = splitString(keywordsAsOneString);
			std::cout << std::endl;
			return std::shared_ptr<TopicCategory>( new TopicCategoryWithKeywords(keywordsVec, categoryName));
		}
	};

	std::vector<std::string> splitString(std::string longString) const {
		std::vector<std::string> outVec;
		std::string delimiter = ",";

		size_t pos = 0;
		std::string token;
		while ((pos = longString.find(delimiter)) != std::string::npos) {
		    token = longString.substr(0, pos);
			boost::algorithm::trim(token);
		    outVec.push_back(token);
		    longString.erase(0, pos + delimiter.length());
		}
		return outVec;
	}
};


#endif //WYKOPMAINDATAALANYZER_CATEGORIESFROMFILEFACTORY_H
