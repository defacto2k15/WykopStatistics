//
// Created by defacto on 30.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_RANDOMDIGGSCREATOR_H
#define WYKOPMAINDATAALANYZER_RANDOMDIGGSCREATOR_H


#include <test/endToEndHelp/diggCharacteristics/DiggTemplate.h>
#include <OneDigg.h>

class RandomDiggsCreator {
public:
	std::vector<OneDigg> createDiggs(DiggTemplate &diggTemplate);

	const OneDigg createRandomDigg();

	std::string createRandomDate();

	std::string createRandomTime();
};


#endif //WYKOPMAINDATAALANYZER_RANDOMDIGGSCREATOR_H
