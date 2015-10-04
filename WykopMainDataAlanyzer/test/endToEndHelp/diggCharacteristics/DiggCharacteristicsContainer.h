//
// Created by defacto on 30.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_DIGGCHARACTERISTICS_H
#define WYKOPMAINDATAALANYZER_DIGGCHARACTERISTICS_H


#include <memory>
#include "DiggTemplate.h"
#include "DiggCharacteristic.h"
#include "DiggTemplateCharacteristic.h"
#include <vector>

class DiggCharacteristicsContainer {

	std::vector<std::shared_ptr<DiggCharacteristic>> diggCharacteristics_;
	std::vector<std::shared_ptr<DiggTemplateCharacteristic>> diggTemplateCharacteristic_;
public:

	static DiggCharacteristicsContainer Create();

	DiggCharacteristicsContainer addDiggCharacteristic(std::shared_ptr<DiggCharacteristic> newDiggCharacteristic);

	DiggCharacteristicsContainer addDiggTemplateCharacteristic( std::shared_ptr<DiggTemplateCharacteristic> diggGroupCharacteristic);

	const std::vector<std::shared_ptr<DiggCharacteristic>> getDiggCharacteristics() const;

	const std::vector<std::shared_ptr<DiggTemplateCharacteristic>> getDiggTemplateCharacteristic() const;
};


#endif //WYKOPMAINDATAALANYZER_DIGGCHARACTERISTICS_H
