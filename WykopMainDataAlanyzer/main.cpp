#include <iostream>
#include <memory>
#include <vector>
#include "pugixml.hpp"
#include "NodesFromXmlFileFetcher.h"
#include "OneDigg.h"
#include "OneDiggFromXPathNodeFactory.h"
#include "ICharacteristicsFetcher.h"
#include "Characteristics/DiggsByDayCounter.h"
#include "Characteristics/DiggsCharacteristicsAcumulator.h"
#include "TopicCategory.h"
#include "TopicCategoryWithKeywords.h"
#include "minicsv.h"
#include "ToCsvExporter.h"
#include "CommonTypes.h"
#include "TopicCategoryWithLambda.h"
#include "CategoriesFromFileFactory.h"

static const int MinimalDiggsNumber = 55;

void RemoveSponsoredDiggs(std::vector<OneDigg> &vector);


std::map< DayName, std::map< Characteristic, CharacteristicValue > > getCharacteristicsByDayMap(
			std::vector<std::shared_ptr<TopicCategory>> topicCategories,
           	std::map< Characteristic, std::function<CharacteristicValue (OneDigg&)> > countingMethodByCharacteristicMap,
			std::vector<OneDigg> diggsOnMainVector );

void RemoveDuplicateDiggs(std::vector<OneDigg> &vec);


std::unique_ptr<pugi::xml_document> openXmlDocument(const std::string &pathToXmlDoc);

void checkArguments(int argc);

int main(int argc, const char **argv) {
	checkArguments(argc);

	std::string pathToXmlDoc = std::string(argv[1]); //"/home/defacto/ProgrammingProjects/WykopProject/AfterOneXml/outXml.xml";
	std::unique_ptr<pugi::xml_document> doc = openXmlDocument(pathToXmlDoc);

	NodesFromXmlFileFetcher fetcher(std::move(doc));
	std::vector<pugi::xpath_node> nodes = fetcher.fetchNodes("/RootDiggs/OneDigg");

	std::vector<OneDigg> diggsOnMainVector;
	OneDiggFromXPathNodeFactory factory;
	for( auto &node : nodes){
		OneDigg digg = (factory.createDigg(node));
		diggsOnMainVector.push_back(digg);
	}
	RemoveSponsoredDiggs(diggsOnMainVector);
	RemoveDuplicateDiggs(diggsOnMainVector);

	const char * pathToCategoriesDoc = argv[2];
	auto categoriesDoc = openXmlDocument(std::string(pathToCategoriesDoc));

	CategoriesFromFileFactory categoriesFactory( std::move( categoriesDoc));

//	std::shared_ptr<TopicCategory> arabCategory (new TopicCategoryWithKeywords (	std::vector<std::string>
//       { "imigran", "islam", "muzułum", "meczet", "uchodźc", "arab", "isis", "dżihad",
//		"uchodź", "imam", "religia pokoju" ,"mahomet", "kozojebc"}, "Islam"));
//
//	std::shared_ptr<TopicCategory> allDiggsCategory( new TopicCategoryWithLambda([](OneDigg& ){return true;}, "AllDiggs"));

	std::vector<std::shared_ptr<TopicCategory>> topicCategories = categoriesFactory.getCategories();//{arabCategory,  allDiggsCategory};

	std::map< Characteristic, std::function<CharacteristicValue (OneDigg&)> > countingMethodByCharacteristicMap{
			{"DiggsOnMain", [](OneDigg& digg){return 1;}},
			{"DiggsCount", [](OneDigg& digg){return digg.getDiggCount();}}
	};

	std::map< DayName, std::map< Characteristic, CharacteristicValue > > characteristicsByDayMap
			= getCharacteristicsByDayMap(topicCategories, countingMethodByCharacteristicMap, diggsOnMainVector);

	const char *pathToOutfile = argv[3];
	ToCsvExporter exporter(pathToOutfile);
	exporter.exportCharacteristics(characteristicsByDayMap);
	return 0;
}

void checkArguments(int argc) {
	if( argc != 4){
		std::cout << "Wrong number of arguments " << std::endl;
		std::cout << "Usage: inputXml categoriesXml outputCsv " << std::endl;
		std::exit(-1);
	}
}

std::unique_ptr<pugi::xml_document> openXmlDocument(const std::string &pathToXmlDoc) {
	std::unique_ptr<pugi::xml_document> doc( new pugi::xml_document);
	auto loadStructure = doc->load_file(pathToXmlDoc.c_str());
	if ( loadStructure == false) {
		std::cout << "Error while loading " << pathToXmlDoc << std::endl;
		std::cout << "Error is: " << loadStructure.description() << std::endl;
		std::exit(-1);
	}
	return doc;
}

void RemoveDuplicateDiggs(std::vector<OneDigg> &vec) {
	std::sort(begin(vec), end(vec),
	          [](OneDigg &digg1, OneDigg &digg2){
		          return digg1.getAddDateWithTime() < digg2.getAddDateWithTime();
	          });
	auto last = std::unique(begin(vec), end(vec),
	                        [](OneDigg& first, OneDigg& last){
		                        return first.getAddDateWithTime() == last.getAddDateWithTime();
	                        });

	vec.erase(last, end(vec));
}

void RemoveSponsoredDiggs(std::vector<OneDigg> &vec){
		vec.erase(remove_if(begin(vec), end(vec),
			[](const OneDigg& digg){return digg.getDiggCount()< MinimalDiggsNumber;}),
		          end(vec));
}

std::map< DayName, std::map< Characteristic, CharacteristicValue > > getCharacteristicsByDayMap(
			std::vector<std::shared_ptr<TopicCategory>> topicCategories,
           	std::map< Characteristic, std::function<CharacteristicValue (OneDigg&)> > countingMethodByCharacteristicMap,
			std::vector<OneDigg> diggsOnMainVector ){
	std::map< DayName, std::map< Characteristic, CharacteristicValue > > characteristicsByDayMap;
	int numberofDiggs = diggsOnMainVector.size();
	int currentDiggNumber = 1;

	for( auto &oneDigg : diggsOnMainVector){
		for( auto &oneTopic: topicCategories){
			if(oneTopic->isDiggOfTopic(oneDigg)){
				for(auto &characteristicAndCountingMethodPair : countingMethodByCharacteristicMap){
					Characteristic characteristicName = oneTopic->getTopicName()+characteristicAndCountingMethodPair.first;
					characteristicsByDayMap[oneDigg.getAddDate()][characteristicName]
							+= characteristicAndCountingMethodPair.second(oneDigg);
				}
			}
		}
		std::cout << "Done diggs ["<<currentDiggNumber<<"/"<<numberofDiggs<<"]"<<std::endl;
		currentDiggNumber++;
	}
	return characteristicsByDayMap;
};
//void RemoveSponsoredDiggs(const std::map<string, vector<OneDigg>> &diggsByDay) {
//	for(auto &pair : diggsByDay){
//		auto vec = pair.second;
//		vec.erase(remove_if(begin(vec), end(vec),
//			[](const OneDigg& digg){return digg.getDiggCount()< MinimalDiggsNumber;}),
//		          end(vec));
//	}
//}