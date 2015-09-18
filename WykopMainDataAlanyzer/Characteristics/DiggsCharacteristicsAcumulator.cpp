//
// Created by defacto on 14.09.15.
//

#include "DiggsCharacteristicsAcumulator.h"

int DiggsCharacteristicsAcumulator::getValueByDay(std::vector<OneDigg> vector) {
	int sum = 0;
	for( auto &oneDigg : vector){
		sum += calculatingFunc(oneDigg);
	}
	return sum;
}
