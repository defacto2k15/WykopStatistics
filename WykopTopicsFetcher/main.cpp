#include "pugixml.hpp"

#include <iostream>
#include "ValuesFromNodeExtractor.h"
#include "DiggData.h"
#include "DiggDataToXmlWriter.h"
#include <fstream>
#include <vector>
#include <bits/unique_ptr.h>
#include <sstream>
#include <typeinfo>
#include <functional>

DiggData extractDiggData(const pugi::xpath_node &node);

int main(int argc, char **argv)
{
    if( argc == 1){
        std::cerr << " At least one argument";
        return -1;
    }
    const char *pathToOutputXml = argv[1];
    std::unique_ptr<std::istream, std::function<void(void*)> > ptr( &std::cin, [&](void* ptr){;});

    if(argc==3){
        std::stringstream* fileStream =  (new std::stringstream);
        (*fileStream) << "/home/defacto/ProgrammingProjects/WykopMainData/wykopSites/index.xml ";
        (*fileStream) << "/home/defacto/ProgrammingProjects/WykopMainData/wykopSites/index2.xml";

        std::unique_ptr<std::istream, std::function<void(void*)> > ptr2( fileStream, [&](void* ptr){ delete (std::istream*)ptr;});
        ptr.swap(ptr2);

        pathToOutputXml = "/home/defacto/ProgrammingProjects/WykopMainData/outputXml/outXml.xml";
    }

    int numberOfProcessedWebsites = 0;
    std::vector<DiggData> diggsVector;
    DiggDataToXmlWriter writer(pathToOutputXml);
    pugi::xml_document doc;
    std::string pathToXmlDoc;
    while( *ptr>>  pathToXmlDoc){
        if (!doc.load_file(pathToXmlDoc.c_str())) {
            std::cout << "Error while loading " << pathToXmlDoc <<std::endl;
            return -1;
        }

        pugi::xpath_query query_wykop_array("(//*[@class=\"link iC\"])|(//*[@class=\"link iC hot\"])");
        pugi::xpath_node_set wykop_nodes = query_wykop_array.evaluate_node_set(doc);

        for( auto& node : wykop_nodes){
            DiggData data = extractDiggData(node);
            diggsVector.push_back(data);
        }
        std:: cout << "processedWebsite: " << numberOfProcessedWebsites << std::endl;
        numberOfProcessedWebsites++;
    }

    for( auto& oneDigg : diggsVector ){
        writer.addOneDiggData(oneDigg);
    }
    writer.saveXmlToFile();

}

DiggData extractDiggData(const pugi::xpath_node &node) {
    ValuesFromNodeExtractor extractor;
    DiggData data(extractor.getValueFromNode(node, "div/div[1]/a/span[1]/text()"),
                          extractor.getAttributeFromNode(node, "div/div[3]/h2/a/@title"),
                          extractor.getAttributeFromNode(node, "div/div[3]/h2/a/@href"),
                          extractor.getValueFromNode(node, "div/div[3]/div[2]/p/a/text()"),
                          extractor.getValueFromNode(node, "div/div[3]/div[3]/a/text()"),
                          extractor.getAttributeFromNode(node, "div/div[3]/div[3]/div[1]/@title"));
    return data;
}





// vim:et
