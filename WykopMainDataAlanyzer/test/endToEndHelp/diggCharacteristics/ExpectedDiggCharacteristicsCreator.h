//
// Created by defacto on 30.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_EXPECTEDDIGGCHARACTERISTICSCREATOR_H
#define WYKOPMAINDATAALANYZER_EXPECTEDDIGGCHARACTERISTICSCREATOR_H


#include <initializer_list>
#include "test/endToEndHelp/diggCharacteristics/ExpectedDiggCharacteristics.h"
#include "DiggCharacteristicsContainer.h"
#include <vector>


class ExpectedDiggCharacteristicsCreator {
	std::vector<DiggCharacteristicsContainer> vectorOfCharacteristicsTemplate_;
public:
	 ExpectedDiggCharacteristicsCreator addCharacteristicsContainers(
			 std::initializer_list<DiggCharacteristicsContainer> listOfCharacteristics);

	ExpectedDiggCharacteristicsCreator addGlobalDiggCharacteristic(
			std::initializer_list<std::shared_ptr<DiggCharacteristic>> list);

	ExpectedDiggCharacteristics create();
};


#endif //WYKOPMAINDATAALANYZER_EXPECTEDDIGGCHARACTERISTICSCREATOR_H
