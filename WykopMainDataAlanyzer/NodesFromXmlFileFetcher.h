//
// Created by defacto on 14.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_NODESFROMXMLFILEFETCHER_H
#define WYKOPMAINDATAALANYZER_NODESFROMXMLFILEFETCHER_H


#include <memory>
#include <vector>
#include "pugixml.hpp"

class NodesFromXmlFileFetcher {

public:
	NodesFromXmlFileFetcher(std::unique_ptr<pugi::xml_document> document) : document(std::move(document)){
	}

	std::vector<pugi::xpath_node> fetchNodes(const char *xpath);

private:
	std::unique_ptr<pugi::xml_document> document;
};


#endif //WYKOPMAINDATAALANYZER_NODESFROMXMLFILEFETCHER_H
