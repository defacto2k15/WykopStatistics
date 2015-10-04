//
// Created by defacto on 02.10.15.
//

#ifndef WYKOPMAINDATAALANYZER_DIGGSVECTORANALYZER_H
#define WYKOPMAINDATAALANYZER_DIGGSVECTORANALYZER_H


#include <vector>
#include <OneDigg.h>

class DiggsVectorAnalyzer {
	std::vector<OneDigg> diggs_;
public:
	DiggsVectorAnalyzer(std::vector <OneDigg> diggsVector);

	std::vector<std::string> getDistinctDates();

	long getDiggsCountOfDate(std::string &addDate);
private:
	std::vector<OneDigg> getDiggsWithUniqueDates() const;
};


#endif //WYKOPMAINDATAALANYZER_DIGGSVECTORANALYZER_H
