//
// Created by defacto on 14.09.15.
//
#include <string>
#ifndef WYKOPMAINDATAALANYZER_ONEDIGG_H
#define WYKOPMAINDATAALANYZER_ONEDIGG_H

#include "boost/date_time/gregorian/gregorian.hpp"

class OneDigg {
private:
	std::string title;
	std::string description;
	int diggCount;
    std::string addDate;
	std::string addDateWithTime;
public:
	OneDigg(const std::string &title, const std::string &description, int diggCount,
	        const std::string &addDate, const std::string &addDateWithTime) :
			title(title), description(description), diggCount(diggCount),
	                                                 addDate(addDate), addDateWithTime(addDateWithTime) { }

	const std::string getTitle() const;

	const std::string getDescription() const;

	int getDiggCount() const;

	const std::string getAddDate() const;

	const std::string &getAddDateWithTime() const {
		return addDateWithTime;
	}
};


#endif //WYKOPMAINDATAALANYZER_ONEDIGG_H
