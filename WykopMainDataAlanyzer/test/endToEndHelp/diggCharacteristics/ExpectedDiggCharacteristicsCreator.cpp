//
// Created by defacto on 30.09.15.
//

#include "ExpectedDiggCharacteristicsCreator.h"
#include <algorithm>

ExpectedDiggCharacteristicsCreator ExpectedDiggCharacteristicsCreator::addCharacteristicsContainers(
        std::initializer_list<DiggCharacteristicsContainer> listOfCharacteristics) {
        std::copy(std::begin( listOfCharacteristics), std::end(listOfCharacteristics), std::back_inserter(this->vectorOfCharacteristicsTemplate_));
        return *this;
}

ExpectedDiggCharacteristicsCreator ExpectedDiggCharacteristicsCreator::addGlobalDiggCharacteristic(
        std::initializer_list<std::shared_ptr<DiggCharacteristic> > list) {
        for( auto &container : this->vectorOfCharacteristicsTemplate_){
                for( auto &characteristic : list){
                       container.addDiggCharacteristic(characteristic);
                }
        }
        return *this;
}

ExpectedDiggCharacteristics ExpectedDiggCharacteristicsCreator::create() {
        return ExpectedDiggCharacteristics(vectorOfCharacteristicsTemplate_);
}
