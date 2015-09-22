//
// Created by defacto on 14.09.15.
//

#include "DiggsByDayCounter.h"

int DiggsByDayCounter::getValueByDay(std::vector<OneDigg> vector) {
	int sum = 0;
	for( auto &oneDigg : vector){
		sum+=oneDigg.getDiggCount();
	}
	return sum;
}
