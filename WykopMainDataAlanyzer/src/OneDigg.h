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
	std::string time;
public:
	OneDigg(const std::string &title, const std::string &description, int diggCount,
	        const std::string &addDate, const std::string &time) :
			title(title), description(description), diggCount(diggCount),
	                                                 addDate(addDate), time(time) { }

	const std::string getTitle() const;

	const std::string getDescription() const;

	int getDiggCount() const;

	const std::string getAddDate() const;

	const std::string getTime() const;

	const std::string getAddDateWithTime() const;
};


#endif //WYKOPMAINDATAALANYZER_ONEDIGG_H
