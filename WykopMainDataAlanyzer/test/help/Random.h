//
// Created by defacto on 23.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_RANDOM_H
#define WYKOPMAINDATAALANYZER_RANDOM_H

#include <vector>
#include <string>
namespace  test {
	class Random {
	private:
		static constexpr const char * alphanum =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		static constexpr const char * num =  "0123456789";
		static bool srandWasSet;
	public:
		static std::string CreateRandomAlphanumericString(int length = 10);

		static std::string CreateRandomPositiveNumberString(int length = 10);

		static int CreateRandomInt();

		static int CreateRandomInt(int min, int max);
	private:
		static std::string CreateRandomStringFromChars(std::vector<char> charVector, int length);

		static int myRand();
	};
}

#endif //WYKOPMAINDATAALANYZER_RANDOM_H
