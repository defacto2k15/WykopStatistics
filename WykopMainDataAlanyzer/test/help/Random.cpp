//
// Created by defacto on 23.09.15.
//

#include "Random.h"

bool test::Random::srandWasSet = false;

std::string test::Random::CreateRandomAlphanumericString(int length) {
	std::string alphanumString( alphanum);
	std::vector<char> charVec {alphanumString.begin(), alphanumString.end()};
	return CreateRandomStringFromChars(charVec, length);
}

std::string test::Random::CreateRandomPositiveNumberString(int length) {
	std::string numString ( num );
	std::vector<char> charVec {numString.begin(), numString.end()};
	return CreateRandomStringFromChars(charVec, length);
}

std::string test::Random::CreateRandomStringFromChars(std::vector<char> charVector, int length) {
	std::string outString;
	for (int i = 0; i < length; ++i) {
		outString += ( charVector[myRand() % (charVector.size() - 1)]);
	}
	return outString;
}

int test::Random::myRand() {
	if(srandWasSet == false){
		srand(time(NULL));
		srandWasSet = true;
	}
	return rand();
}

int test::Random::CreateRandomInt() {
	return myRand();
}

int test::Random::CreateRandomInt(int min, int max) {
	return min + ( myRand() % (max - min));
}
