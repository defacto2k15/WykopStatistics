//
// Created by defacto on 24.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_INPUTFILECONSTANTS_H
#define WYKOPMAINDATAALANYZER_INPUTFILECONSTANTS_H

#include <string>
#include <sstream>

class InputFileConstants {
private:
	static constexpr char const * rootNodeName = "RootDiggs";
	static constexpr char const * diggNodeName = "OneDigg";
	static constexpr char const * diggNameNodeName = "title";
	static constexpr char const * diggDescriptionNodeName = "description";
	static constexpr char const * diggTimeNodeName = "time";
	static constexpr char const * diggCountNodeName = "diggCount";
public:
	static std::string getRootNodeName();

	static std::string getDiggNameNodeName() {
		return diggNameNodeName;
	}

	static std::string getDiggDescriptionNodeName() {
		return diggDescriptionNodeName;
	}

	static std::string getDiggTimeNodeName() {
		return diggTimeNodeName;
	}

	static std::string getDiggCountNodeName() {
		return diggCountNodeName;
	}

	static std::string getDiggNodeName();

	static std::string getPathToDiggNodes();
};


#endif //WYKOPMAINDATAALANYZER_INPUTFILECONSTANTS_H
