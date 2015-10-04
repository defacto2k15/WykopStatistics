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
#include <test/endToEndHelp/diggCharacteristics/ExpectedDiggCharacteristicsCreator.h>
#include <test/endToEndHelp/diggCharacteristics/Day.h>
#include <test/endToEndHelp/diggCharacteristics/MinimalDiggsNumber.h>
#include <test/endToEndHelp/diggCharacteristics/OneDiggCount.h>
#include <test/endToEndHelp/diggCharacteristics/DiggsCount.h>


using namespace std;
namespace test {
	class EndToEndTests : public ::testing::Test {
	protected:
		TempFile tempInputFile;
		TempFile outFile;
		TempFile tempCategoriesFile;
		CategoriesFileCreator categoriesCreator;
		InputXmlCreator inputCreator;
		ApplicationRunner WmdaRunner;
		std::shared_ptr<OutFileAsserter> outFileAsserter;
		ExpectedDiggCharacteristicsCreator characteristicsCreator;


		EndToEndTests() : tempInputFile("xml"), outFile(""), tempCategoriesFile("xml"){}

		virtual void SetUp(){
			outFileAsserter = std::shared_ptr<OutFileAsserter>(new OutFileAsserter(outFile.getPath()));
//			tempInputFile = std::make_shared<TempFile>(new TempFile("xml"));
//			outFile = std::make_shared<TempFile>(new TempFile());
//			tempCategoriesFile = std::make_shared<TempFile>("xml");
		}

		virtual void TearDown(){
			tempInputFile.clearFileContent();
			outFile.clearFileContent();
			tempCategoriesFile.clearFileContent();
		}

	};


	TEST_F(EndToEndTests, FindingAllDiggsPerMonthTest ){
		string allCategoryName{"AllCategory"};

		categoriesCreator.addAllCategory(allCategoryName);
		categoriesCreator.writeToFile(tempCategoriesFile.getPath());

		std::vector<std::pair<DayName, int>> expectedDiggsNumberByDay {
				{"2015-01-04", 21},
				{"2014-03-30", 1},
				{"2013-03-29", 13}
		};

		for( auto &pair : expectedDiggsNumberByDay){
			characteristicsCreator.addCharacteristicsContainers(
				{
					DiggCharacteristicsContainer::Create()
							.addDiggCharacteristic(day(pair.first))
							.addDiggTemplateCharacteristic(oneDiggCount(pair.second))
				});
		}
		characteristicsCreator.addGlobalDiggCharacteristic(
				{
                  minimalDiggsNumber(100)
				});

		ExpectedDiggCharacteristics diggCharacteristics = characteristicsCreator.create();
		std::vector<OneDigg> createdDiggs  = diggCharacteristics.createDiggs();
		inputCreator.createWithDiggs(createdDiggs);
		inputCreator.writeToFile(tempInputFile.getPath());

		WmdaRunner.runWithParamerers({ tempInputFile.getPath(), tempCategoriesFile.getPath(), outFile.getPath() });

		outFileAsserter->assertRowNumberEquals(expectedDiggsNumberByDay.size() + 1);
		for( auto  &pair : expectedDiggsNumberByDay ){
				outFileAsserter->assertContainsRowWithValues({ {"Date", pair.first},
					                                      {allCategoryName + "DiggsOnMain",
							                                      to_string(pair.second)}
			                                            });
		}
		outFileAsserter->assertContainsColumns({"Date",allCategoryName+"DiggsOnMain" });
	}

	struct ExpectedDateOneDiggsCountDiggsCount{
		std::string date;
		int oneDiggsCount;
		int diggsPerOneDiggCount;
	};

	TEST_F(EndToEndTests, FindDiggCountPerMonthTest ) {
		string allCategoryName{"AllCategory"};
		categoriesCreator.addAllCategory(allCategoryName);
		categoriesCreator.writeToFile(tempCategoriesFile.getPath());

		std::vector<ExpectedDateOneDiggsCountDiggsCount> expectedDatas{
				{"2015-01-04", 1, 140},
				{"2015-01-05", 3,  342},
				{"2015-12-01", 2, 421}
		};

		for (auto &oneExpectedData : expectedDatas) {
			characteristicsCreator.addCharacteristicsContainers(
					{
							DiggCharacteristicsContainer::Create()
									.addDiggCharacteristic(day(oneExpectedData.date))
									.addDiggCharacteristic(diggsCount(oneExpectedData.diggsPerOneDiggCount))
									.addDiggTemplateCharacteristic(oneDiggCount(oneExpectedData.oneDiggsCount))
					});
		}
		characteristicsCreator.addGlobalDiggCharacteristic(
				{
						minimalDiggsNumber(100)
				});

		ExpectedDiggCharacteristics diggCharacteristics = characteristicsCreator.create();
		std::vector<OneDigg> createdDiggs = diggCharacteristics.createDiggs();
		inputCreator.createWithDiggs(createdDiggs);
		inputCreator.writeToFile(tempInputFile.getPath());

		WmdaRunner.runWithParamerers({tempInputFile.getPath(), tempCategoriesFile.getPath(), outFile.getPath()});

		for( auto &expectedDataElement : expectedDatas){
			outFileAsserter->assertContainsRowWithValues(
					{
							{"Date", expectedDataElement.date},
							{allCategoryName+"DiggsCount", std::to_string(
									expectedDataElement.diggsPerOneDiggCount*expectedDataElement.oneDiggsCount)}
			        });
		}
	}
}