//
// Created by defacto on 08.09.15.
//

#ifndef WYKOPTOPICSFETCHER_VALUESFROMNODEEXTRACTOR_H
#define WYKOPTOPICSFETCHER_VALUESFROMNODEEXTRACTOR_H

class ValuesFromNodeExtractor {
public:
    const std::string getValueFromNode(const pugi::xpath_node node, const char *xPathToValue);

    const std::string getAttributeFromNode(const pugi::xpath_node node, const char *xPathToValue) ;
};


#endif //WYKOPTOPICSFETCHER_VALUESFROMNODEEXTRACTOR_H
