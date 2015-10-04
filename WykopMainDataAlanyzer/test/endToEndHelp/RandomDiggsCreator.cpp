//
// Created by defacto on 30.09.15.
//

#include <test/help/Random.h>
#include "RandomDiggsCreator.h"

std::vector<OneDigg> RandomDiggsCreator::createDiggs(DiggTemplate &diggTemplate) {
	std::vector<OneDigg> outVec;
	for( int i = 0; i < diggTemplate.amountOfDiggsToGenerate; i++){
		outVec.push_back(createRandomDigg());
	}
	return outVec;
}

const OneDigg RandomDiggsCreator::createRandomDigg() {
	return OneDigg(test::Random::CreateRandomAlphanumericString(),
					test::Random::CreateRandomAlphanumericString(),
					test::Random::CreateRandomInt(0, 2000),
					createRandomDate(),
					createRandomTime());
}

std::string RandomDiggsCreator::createRandomDate() {
	std::stringstream ss;
	ss << (2006 + test::Random::CreateRandomInt(0,12) ) << "-";
	ss << test::Random::CreateRandomInt(1,12) << "-";
	ss << test::Random::CreateRandomInt(1,30);
	return ss.str();
}

std::string RandomDiggsCreator::createRandomTime() {
	std::stringstream output;
	std::stringstream ss;
	ss << std::setfill('0') <<std::setw(2) << (test::Random::CreateRandomInt() % 24);
	output << ss.str()<<":";
	ss.str("");
	ss << std::setfill('0') <<std::setw(2) << (test::Random::CreateRandomInt()%60);
	output << ss.str()<<":";
	ss.str("");
	ss << std::setfill('0') <<std::setw(2) << (test::Random::CreateRandomInt()%60);

	output << ss.str();
	return output.str();
}
