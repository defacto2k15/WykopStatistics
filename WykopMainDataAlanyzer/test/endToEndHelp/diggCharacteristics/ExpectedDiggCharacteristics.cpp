//
// Created by defacto on 30.09.15.
//

#include <test/endToEndHelp/RandomDiggsCreator.h>
#include "ExpectedDiggCharacteristics.h"

ExpectedDiggCharacteristics::ExpectedDiggCharacteristics(
		std::vector<DiggCharacteristicsContainer> characteristicsContainer) : characteristicsContainers_(characteristicsContainer) {
}

std::vector<OneDigg> ExpectedDiggCharacteristics::createDiggs() {
	std::vector<OneDigg> outVector;
	RandomDiggsCreator diggsCreator;

	for( auto &container : characteristicsContainers_ ){
		DiggTemplate newTemplate;
		for( auto &oneTemplateCharacteristic : container.getDiggTemplateCharacteristic()){
			oneTemplateCharacteristic->changeTemplate( newTemplate);
		}

		std::vector<OneDigg> diggs = diggsCreator.createDiggs(newTemplate);
		for( OneDigg &digg : diggs) {
			for (auto &oneCharacteristic : container.getDiggCharacteristics()) {
				digg = oneCharacteristic->changeDigg(digg);
			}
		}

		std::copy(begin(diggs), end(diggs), back_inserter(outVector));
	}

	return outVector;
}

unsigned long ExpectedDiggCharacteristics::getTemplateCount() {
	return characteristicsContainers_.size();
}
