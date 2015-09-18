//
// Created by defacto on 14.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_TOPICATEGORYWITHPHRASES_H
#define WYKOPMAINDATAALANYZER_TOPICATEGORYWITHPHRASES_H
#include "TopicCategory.h"

class TopicCategoryWithKeywords : public TopicCategory {

public:
	TopicCategoryWithKeywords(const std::vector<std::string> keywordsVec, const std::string &TopicName)
			: keywords(keywordsVec), TopicCategory(TopicName)
				{ }

	virtual bool isDiggOfTopic(OneDigg &digg){
		for( auto &oneKeyword : keywords){
			if( findStringIC(digg.getTitle(), oneKeyword ) ||
			    findStringIC(digg.getDescription(),oneKeyword)	){
				return true;
			}
		}
		return false;
	}

private:
	std::vector<std::string> keywords;

	bool findStringIC(const std::string & strHaystack, const std::string & strNeedle)
	{
		auto it = std::search(
				begin(strHaystack), end(strHaystack),
				begin(strNeedle),   end(strNeedle),
				[](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
		);
		return (it != strHaystack.end() );
	}
};


#endif //WYKOPMAINDATAALANYZER_TOPICATEGORYWITHPHRASES_H
