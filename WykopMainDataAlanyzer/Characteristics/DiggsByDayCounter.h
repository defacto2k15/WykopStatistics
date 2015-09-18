//
// Created by defacto on 14.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_DIGGSBYDAYCOUNTER_H
#define WYKOPMAINDATAALANYZER_DIGGSBYDAYCOUNTER_H


#include "../ICharacteristicsFetcher.h"

class DiggsByDayCounter : public ICharacteristicsFetcher{

public:
	virtual int getValueByDay(std::vector<OneDigg> vector);
};


#endif //WYKOPMAINDATAALANYZER_DIGGSBYDAYCOUNTER_H
