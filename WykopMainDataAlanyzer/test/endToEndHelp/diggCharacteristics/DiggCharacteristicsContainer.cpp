//
// Created by defacto on 30.09.15.
//

#include "DiggCharacteristicsContainer.h"

DiggCharacteristicsContainer DiggCharacteristicsContainer::Create() {
	return DiggCharacteristicsContainer();
}

DiggCharacteristicsContainer DiggCharacteristicsContainer::addDiggCharacteristic(
		std::shared_ptr<DiggCharacteristic> newDiggCharacteristic) {
	this->diggCharacteristics_.push_back(newDiggCharacteristic);
	return *this;
}

const std::vector<std::shared_ptr<DiggCharacteristic>> DiggCharacteristicsContainer::getDiggCharacteristics() const {
	return diggCharacteristics_;
}

DiggCharacteristicsContainer DiggCharacteristicsContainer::addDiggTemplateCharacteristic(
		std::shared_ptr<DiggTemplateCharacteristic> diggGroupCharacteristic) {
	this->diggTemplateCharacteristic_.push_back(diggGroupCharacteristic);
	return *this;
}

const std::vector<std::shared_ptr<DiggTemplateCharacteristic>> DiggCharacteristicsContainer::getDiggTemplateCharacteristic() const {
	return diggTemplateCharacteristic_;
}