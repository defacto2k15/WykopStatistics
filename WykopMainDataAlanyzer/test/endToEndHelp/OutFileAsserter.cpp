//
// Created by defacto on 25.09.15.
//

#include "OutFileAsserter.h"
#include <string>
#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include "test/help/ToString.h"
OutFileAsserter::OutFileAsserter(const char *pathToFile) : analyzer_(pathToFile){
}


void OutFileAsserter::assertRowNumberEquals(unsigned long expectedRowsNumber) {
	ASSERT_EQ(expectedRowsNumber, analyzer_.getRowNumber()) << std::string("Rows number in out csv file is not equal to expected") << help::to_String(expectedRowsNumber);
}

void OutFileAsserter::assertContainsRowWithValues(std::vector<std::pair<std::string, std::string>> expectedColumnValuePairs) {
	ASSERT_TRUE(analyzer_.containsRowWithValues(expectedColumnValuePairs)) << "Dont contain expected column value pairs" << help::to_String(expectedColumnValuePairs);
}

void OutFileAsserter::assertContainsColumns(std::vector<std::string> expectedColumnsNames) {
	ASSERT_TRUE(analyzer_.containsColumns(expectedColumnsNames)) << "Dont contains expected column names";
}
