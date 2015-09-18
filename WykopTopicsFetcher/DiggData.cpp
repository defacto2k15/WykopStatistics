//
// Created by defacto on 08.09.15.
//

#include <iostream>
#include "pugixml.hpp"
#include "DiggData.h"

const std::string DiggData::getDiggCount() const {
    return diggCount;
}

const std::string DiggData::getDiggTitle() const {
    return diggTitle;
}

const std::string DiggData::getDiggLink() const {
    return diggLink;
}

const std::string DiggData::getDiggDescription() const {
    return diggDescription;
}

const std::string DiggData::getDiggCommentsCount() const {
    return diggCommentsCount;
}

const std::string DiggData::getDiggTime() const {
    return diggTime;
}