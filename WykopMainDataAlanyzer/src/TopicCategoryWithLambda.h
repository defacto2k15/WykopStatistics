//
// Created by defacto on 14.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_TOPICCATEGORYWITHLAMBDA_H
#define WYKOPMAINDATAALANYZER_TOPICCATEGORYWITHLAMBDA_H


#include <functional>
#include "OneDigg.h"
#include "TopicCategory.h"

class TopicCategoryWithLambda : public TopicCategory{
public:
	TopicCategoryWithLambda(std::function<bool (OneDigg&)> checkingLambda, const std::string topicTitle)
			: TopicCategory(topicTitle), checkingLambda(checkingLambda)
	{}

	virtual bool isDiggOfTopic(OneDigg &digg){
		return checkingLambda(digg);
	}

private:
	std::function<bool (OneDigg&)> checkingLambda;
};


#endif //WYKOPMAINDATAALANYZER_TOPICCATEGORYWITHLAMBDA_H
