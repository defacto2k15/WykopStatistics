//
// Created by defacto on 30.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_DIGGCOUNT_H
#define WYKOPMAINDATAALANYZER_DIGGCOUNT_H


#include "DiggCharacteristic.h"
#include "DiggTemplateCharacteristic.h"
#include <memory>
#include <OneDigg.h>

class OneDiggCount : public DiggTemplateCharacteristic{
	int count_;
public:
	OneDiggCount(int count );;
	virtual void changeTemplate(DiggTemplate &diggTemplate) override;

	int getCount_() const;
};

std::shared_ptr<DiggTemplateCharacteristic> oneDiggCount(int count);

#endif //WYKOPMAINDATAALANYZER_DIGGCOUNT_H
