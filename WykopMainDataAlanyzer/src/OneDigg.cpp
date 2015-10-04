//
// Created by defacto on 14.09.15.
//

#include "OneDigg.h"

const std::string OneDigg::getTitle() const {
	return title;
}

const std::string OneDigg::getDescription() const {
	return description;
}

int OneDigg::getDiggCount() const {
	return diggCount;
}

const std::string OneDigg::getAddDate() const {
	return addDate;
}

const std::string OneDigg::getTime() const {
	return time;
}

const std::string OneDigg::getAddDateWithTime() const {
	return getAddDate()+" "+getTime();
}
