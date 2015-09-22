//
// Created by defacto on 14.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_DIGGSCHARACTERISTICSACUMULATOR_H
#define WYKOPMAINDATAALANYZER_DIGGSCHARACTERISTICSACUMULATOR_H


#include "../ICharacteristicsFetcher.h"

class DiggsCharacteristicsAcumulator : public ICharacteristicsFetcher {
public:
	DiggsCharacteristicsAcumulator(std::function<int (OneDigg&)> calculatingFunc) : calculatingFunc(calculatingFunc){}
	virtual int getValueByDay(std::vector<OneDigg> vector);
private:
	std::function<int (OneDigg&)> calculatingFunc;
};


#endif //WYKOPMAINDATAALANYZER_DIGGSCHARACTERISTICSACUMULATOR_H
