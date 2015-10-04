//
// Created by defacto on 30.09.15.
//

#include <OneDigg.h>
#include "Day.h"

Day::Day(std::string day) : day_(day) {}

OneDigg Day::changeDigg(OneDigg aDigg) {
	return OneDigg(aDigg.getTitle(), aDigg.getDescription(), aDigg.getDiggCount(), day_, aDigg.getTime());
}

std::shared_ptr<DiggCharacteristic> day(std::string string) {
	return std::make_shared<Day>(string);
}