//
// Created by defacto on 23.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_CHARACTERISTICFILECONSTANTS_H
#define WYKOPMAINDATAALANYZER_CHARACTERISTICFILECONSTANTS_H

#include <string>
using namespace std;

class CharacteristicFileConstants {
private:
	static constexpr char const * const rootNodeName = "categories";
	static constexpr char const * const categoryNodeName = "category";
	static constexpr char const * const categoryNameNodeName = "name";
	static constexpr char const * const categoryKeywordsNodeName = "keywords";
public:

	static const string getRootNodeName() ;

	static const string getCategoryNodeName() ;

	static const string getCategoryNameNodeName() ;

	static const string getCategoryKeywordsNodeName() ;
};


#endif //WYKOPMAINDATAALANYZER_CHARACTERISTICFILECONSTANTS_H
