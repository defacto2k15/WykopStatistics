//
// Created by defacto on 30.09.15.
//

#include <OneDigg.h>
#include "MinimalDiggsNumber.h"

MinimalDiggsNumber::MinimalDiggsNumber(int diggNumber) : minimalDiggNumber_(diggNumber){
}

OneDigg MinimalDiggsNumber::changeDigg(OneDigg aDigg) {
	int diggCount = aDigg.getDiggCount();
	if( diggCount < minimalDiggNumber_){
		diggCount += minimalDiggNumber_;
	}
	return OneDigg( aDigg.getTitle(), aDigg.getDescription(), diggCount, aDigg.getAddDate(), aDigg.getTime());
}

std::shared_ptr<DiggCharacteristic> minimalDiggsNumber( int diggNumber ) {
	return std::make_shared<MinimalDiggsNumber>(diggNumber);
}