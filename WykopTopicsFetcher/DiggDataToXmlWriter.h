//
// Created by defacto on 08.09.15.
//

#ifndef WYKOPTOPICSFETCHER_DIGGDATATOXMLWRITER_H
#define WYKOPTOPICSFETCHER_DIGGDATATOXMLWRITER_H


#include <iosfwd>
#include <fstream>
#include "pugixml.hpp"
#include "DiggData.h"

class DiggDataToXmlWriter {
private:
    std::ofstream xmlFileStream;
    pugi::xml_document xmlDoc;
    pugi::xml_node rootNode;

    void addTextNode(pugi::xml_node node, const char *string, const std::string basic_string);

public:

    virtual ~DiggDataToXmlWriter();

    DiggDataToXmlWriter(const char *pathToXmlFile);

    void addOneDiggData(DiggData node);

    void saveXmlToFile();
};


#endif //WYKOPTOPICSFETCHER_DIGGDATATOXMLWRITER_H
