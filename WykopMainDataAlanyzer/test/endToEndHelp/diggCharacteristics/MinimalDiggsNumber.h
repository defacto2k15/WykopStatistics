//
// Created by defacto on 30.09.15.
//

#include <bits/shared_ptr.h>
#include <OneDigg.h>
#include "DiggCharacteristic.h"

#ifndef WYKOPMAINDATAALANYZER_MINIMALDIGGSNUMBER_H
#define WYKOPMAINDATAALANYZER_MINIMALDIGGSNUMBER_H
class MinimalDiggsNumber : public DiggCharacteristic {
	int minimalDiggNumber_;
public:
	MinimalDiggsNumber(int diggNumber);

	virtual OneDigg changeDigg(OneDigg aTemplate) override ;
};

std::shared_ptr<DiggCharacteristic> minimalDiggsNumber( int diggNumber );
#endif //WYKOPMAINDATAALANYZER_MINIMALDIGGSNUMBER_H
