//
// Created by defacto on 02.10.15.
//

#include "DiggsVectorAnalyzer.h"

DiggsVectorAnalyzer::DiggsVectorAnalyzer(std::vector<OneDigg> diggsVector) : diggs_(diggsVector){
}

std::vector<std::string> DiggsVectorAnalyzer::getDistinctDates() {
	std::vector<OneDigg> tempVec = getDiggsWithUniqueDates();

	std::vector<std::string> datesVec;
	std::transform(begin(tempVec), end(tempVec), std::back_inserter(datesVec),
	               [](const OneDigg& digg){return digg.getAddDate();});
	return datesVec;
}

std::vector<OneDigg> DiggsVectorAnalyzer::getDiggsWithUniqueDates() const {
	std::vector<OneDigg> tempVec(diggs_);
	sort(begin(tempVec), end(tempVec),
      [](const OneDigg &first, const OneDigg &second){
			return first.getAddDate() < second.getAddDate();
      });
	auto it = unique(begin(tempVec), end(tempVec),
		       [](const OneDigg &first, const OneDigg &second){
						return first.getAddDate() == second.getAddDate();
		       });
	tempVec.resize( std::distance(tempVec.begin(),it), OneDigg("NOT_USED","NOT_USED", 0, "NOT_USED", "NOT_USED") );
	return tempVec;
}

long DiggsVectorAnalyzer::getDiggsCountOfDate(std::string &addDate) {
	return std::count_if(begin(diggs_), end(diggs_), [&](const OneDigg &digg){return digg.getAddDate() == addDate;});
}
