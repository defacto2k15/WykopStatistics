//
// Created by defacto on 30.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_DAY_H
#define WYKOPMAINDATAALANYZER_DAY_H

#include "DiggTemplate.h"
#include "DiggCharacteristic.h"
#include <string>
#include <memory>

class Day : public DiggCharacteristic {
	std::string day_;
public:
	Day(std::string day);
	virtual OneDigg changeDigg(OneDigg aTemplate) override;
};

std::shared_ptr<DiggCharacteristic> day(std::string string);


#endif //WYKOPMAINDATAALANYZER_DAY_H
