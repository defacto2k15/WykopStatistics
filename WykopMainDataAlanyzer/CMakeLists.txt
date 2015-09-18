cmake_minimum_required(VERSION 3.0)
project(WykopMainDataAlanyzer)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp OneDigg.cpp OneDigg.h pugixml.cpp
        NodesFromXmlFileFetcher.cpp NodesFromXmlFileFetcher.h
        OneDiggFromXPathNodeFactory.cpp OneDiggFromXPathNodeFactory.h
        ValuesFromNodeExtractor.cpp ICharacteristicsFetcher.cpp ICharacteristicsFetcher.h Characteristics/DiggsByDayCounter.cpp Characteristics/DiggsByDayCounter.h Characteristics/DiggsCharacteristicsAcumulator.cpp Characteristics/DiggsCharacteristicsAcumulator.h TopicCategory.cpp TopicCategory.h TopicCategoryWithKeywords.cpp TopicCategoryWithKeywords.h TopicCategoryWithLambda.cpp TopicCategoryWithLambda.h ToCsvExporter.cpp ToCsvExporter.h CategoriesFromFileFactory.cpp CategoriesFromFileFactory.h)
add_executable(WykopMainDataAlanyzer ${SOURCE_FILES})

TARGET_LINK_LIBRARIES( WykopMainDataAlanyzer ${Boost_LIBRARIES} )