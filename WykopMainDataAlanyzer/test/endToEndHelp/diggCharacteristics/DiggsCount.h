//
// Created by defacto on 02.10.15.
//

#ifndef WYKOPMAINDATAALANYZER_DIGGSCOUNT_H
#define WYKOPMAINDATAALANYZER_DIGGSCOUNT_H

#include "DiggCharacteristic.h"
#include <memory>

class DiggsCount : public DiggCharacteristic {
	int constantDiggCount_;

public:
	DiggsCount(int count);
	virtual OneDigg changeDigg(OneDigg digg) override;
};

std::shared_ptr<DiggsCount> diggsCount(int count);

#endif //WYKOPMAINDATAALANYZER_DIGGSCOUNT_H
