//
// Created by defacto on 30.09.15.
//

#include <OneDigg.h>
#include "OneDiggCount.h"

OneDiggCount::OneDiggCount(int count ) : count_(count) {}

int OneDiggCount::getCount_() const {
	return count_;
}

void OneDiggCount::changeTemplate(DiggTemplate &diggTemplate) {
	diggTemplate.amountOfDiggsToGenerate = count_;
}

std::shared_ptr<DiggTemplateCharacteristic> oneDiggCount(int count) {
	return std::make_shared<OneDiggCount>(count);
}