//
// Created by defacto on 23.09.15.
//
#include <string>
#include <CommonTypes.h>
#include <map>
#include <test/endToEndHelp/InputXmlCreator.h>
#include <test/endToEndHelp/OutFileAsserter.h>
#include "help/TempFile.h"
#include "endToEndHelp/CategoriesFileCreator.h"
#include "gtest/gtest.h"
#include "endToEndHelp/ApplicationRunner.h"
#include "endToEndHelp/OutFileAnalyzer.h"

using namespace std;
namespace test {

	TEST(EndToEndTests, FindingAllDiggsPerMonthTest ){
		TempFile tempCategoriesFile("xml");
		CategoriesFileCreator categoriesCreator;
		string allCategoryName{"AllCategory"};

		categoriesCreator.addAllCategory(allCategoryName);
		categoriesCreator.writeToFile(tempCategoriesFile.getPath());

		std::map<DayName, int> expectedDiggsNumberByDay {
				{"2015-01-04", 21},
				{"2014-03-30", 1},
				{"2013-03-29", 13}
		};

		TempFile tempInputFile("xml");
		InputXmlCreator inputCreator;
		inputCreator.createDiggsWithRandomInfo().AmountByDays(expectedDiggsNumberByDay).WithMinimialDiggsNumber(100).Create();
		inputCreator.writeToFile(tempInputFile.getPath());

		TempFile outFile;
		ApplicationRunner WmdaRunner;
		WmdaRunner.runWithParamerers({ tempInputFile.getPath(), tempCategoriesFile.getPath(), outFile.getPath() });
		OutFileAsserter outFileAsserter(outFile.getPath());
		outFileAsserter.assertRowNumberEquals(expectedDiggsNumberByDay.size() + 1);
		for( auto it = expectedDiggsNumberByDay.begin(); it != expectedDiggsNumberByDay.end(); it++ ){
			auto pair = *it;
			outFileAsserter.assertContainsRowWithValues({
					                                  std::make_pair("Date", pair.first),
					                                  std::make_pair(allCategoryName + "DiggsOnMain",
					                                                 to_string(pair.second))
			                                  });
		}
		outFileAsserter.assertContainsColumns({"Date",allCategoryName+"DiggsOnMain" });
	}

}