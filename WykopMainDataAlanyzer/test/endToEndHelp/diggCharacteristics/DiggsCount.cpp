//
// Created by defacto on 02.10.15.
//

#include "DiggsCount.h"

DiggsCount::DiggsCount(int count) : constantDiggCount_(count){
}

OneDigg DiggsCount::changeDigg(OneDigg digg) {
	return OneDigg(digg.getTitle(), digg.getDescription(), constantDiggCount_, digg.getAddDate(), digg.getTime());
}

std::shared_ptr<DiggsCount> diggsCount(int count){
	return std::make_shared<DiggsCount>(count);
}
