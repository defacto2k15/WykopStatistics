//
// Created by defacto on 14.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_TOPICCATEGORY_H
#define WYKOPMAINDATAALANYZER_TOPICCATEGORY_H


#include <string>
#include <vector>
#include "OneDigg.h"

class TopicCategory {

private:
public:
	TopicCategory( const std::string &TopicName) : TopicName(TopicName) { }
	const std::string getTopicName() const {
		return TopicName;
	}

	virtual bool isDiggOfTopic(OneDigg &digg)=0;

private:
	std::string TopicName;
};


#endif //WYKOPMAINDATAALANYZER_TOPICCATEGORY_H
