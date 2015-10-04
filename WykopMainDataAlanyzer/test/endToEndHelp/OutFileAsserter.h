//
// Created by defacto on 25.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_OUTFILEASSERTER_H
#define WYKOPMAINDATAALANYZER_OUTFILEASSERTER_H


#include <vector>
#include <string>
#include "OutFileAnalyzer.h"

class OutFileAsserter {
	OutFileAnalyzer analyzer_;
public:
	OutFileAsserter(const char *pathToFile);

	void assertRowNumberEquals(unsigned long expectedRowsNumber);

	void assertContainsRowWithValues(std::vector <std::pair<std::string, std::string>> expectedColumnValuePairs);

	void assertContainsColumns(std::vector<std::string> expectedColumnsNames);

};


#endif //WYKOPMAINDATAALANYZER_OUTFILEASSERTER_H
