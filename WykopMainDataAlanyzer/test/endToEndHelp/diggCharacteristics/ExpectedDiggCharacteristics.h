//
// Created by defacto on 30.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_EXPECTEDDIGGCHARACTERISTICS_H
#define WYKOPMAINDATAALANYZER_EXPECTEDDIGGCHARACTERISTICS_H


#include <vector>
#include <OneDigg.h>
#include "DiggCharacteristicsContainer.h"

class ExpectedDiggCharacteristics {
	std::vector<DiggCharacteristicsContainer> characteristicsContainers_;
public:
	ExpectedDiggCharacteristics( std::vector<DiggCharacteristicsContainer> characteristicsContainer);
	std::vector<OneDigg> createDiggs();

	unsigned long getTemplateCount();
};


#endif //WYKOPMAINDATAALANYZER_EXPECTEDDIGGCHARACTERISTICS_H
