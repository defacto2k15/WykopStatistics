//
// Created by defacto on 14.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_ICHARACTERISTICSFETCHER_H
#define WYKOPMAINDATAALANYZER_ICHARACTERISTICSFETCHER_H


#include "OneDigg.h"

class ICharacteristicsFetcher {
public:
	virtual int getValueByDay( std::vector<OneDigg> )=0;
	virtual ~ICharacteristicsFetcher(){};
};


#endif //WYKOPMAINDATAALANYZER_ICHARACTERISTICSFETCHER_H
