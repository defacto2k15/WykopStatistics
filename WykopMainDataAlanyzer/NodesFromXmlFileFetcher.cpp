//
// Created by defacto on 14.09.15.
//

#include <vector>
#include "NodesFromXmlFileFetcher.h"

std::vector<pugi::xpath_node> NodesFromXmlFileFetcher::fetchNodes(const char *xpath) {
        pugi::xpath_query query_wykop_array(xpath);
        pugi::xpath_node_set wykop_nodes = query_wykop_array.evaluate_node_set(*document);
        std::vector<pugi::xpath_node> vecToReturn(wykop_nodes.begin(), wykop_nodes.end());
        return vecToReturn;
}
