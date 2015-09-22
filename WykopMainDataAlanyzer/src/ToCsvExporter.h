//
// Created by defacto on 15.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_TOCSVEXPORTER_H
#define WYKOPMAINDATAALANYZER_TOCSVEXPORTER_H

#include <map>
#include "CommonTypes.h"
#include "minicsv.h"
#include <vector>
#include <iostream>

class ToCsvExporter {

public:
	ToCsvExporter(const char *csvFileName);
	void exportCharacteristics( std::map< DayName, std::map< Characteristic, CharacteristicValue > > characteristicsByDayMap){

		std::map< Characteristic , int > columnNumberByCharacteristicMap{{"Date", 0}};

		csv::ofstream os(this->csvFileName);
		os.set_delimiter(',');
		if(os.is_open())
		{
			for( auto &dayAndCharacteristicPair : characteristicsByDayMap ){
				std::map<int, std::string> valuesByColumnNumber;
				std::string date = dayAndCharacteristicPair.first;
				valuesByColumnNumber[0] = date;

				for( auto &characteristicNameAndValuePair : dayAndCharacteristicPair.second){
					if(characteristicIsWrittenFirstTime(columnNumberByCharacteristicMap, characteristicNameAndValuePair.first)){
						setColumnNumberForCharacteristic(columnNumberByCharacteristicMap,
						                                 characteristicNameAndValuePair.first);
					}

					addCharacteristicValueToMap(columnNumberByCharacteristicMap, valuesByColumnNumber,
					                     characteristicNameAndValuePair.first, characteristicNameAndValuePair.second);
				}

				std::vector<std::string> rowValues = createRowValuesVector(valuesByColumnNumber);
				writeOneRowToCsv(os, rowValues);
			}
			addColumnNames(columnNumberByCharacteristicMap, os);
		} else {
			std::cerr << "Cant open CSV file for output";
		}
		os.flush();

	}

private:

	const char *csvFileName;

	void writeOneRowToCsv(csv::ofstream &os, const std::vector<std::string> &rowValues) const {
		for( auto &oneCellValue : rowValues){
			os << oneCellValue;
		}
		os << NEWLINE;
	}

	std::vector<std::string> createRowValuesVector(std::map<int, std::string> &valuesByColumnNumber) const {
		int lastColumnNumber = valuesByColumnNumber.rbegin()->first;
		std::vector<std::string> rowValues(lastColumnNumber+1 );
		for( auto &cellValueWithColumnNumberPair : valuesByColumnNumber){
			rowValues[cellValueWithColumnNumberPair.first] = cellValueWithColumnNumberPair.second;
		}
		return rowValues;
	}


	void setColumnNumberForCharacteristic(std::map<Characteristic, int> &columnNumberByCharacteristicMap,
	                                      const Characteristic characteristic) const {
		int lastColumnNumber = columnNumberByCharacteristicMap.size();
		columnNumberByCharacteristicMap[characteristic] = lastColumnNumber;
	}

	bool characteristicIsWrittenFirstTime(const std::map<Characteristic, int> &columnNumberByCharacteristicMap,
	                                      const Characteristic characteristic) const {
		return columnNumberByCharacteristicMap.count(characteristic) == 0;
	}

	void addCharacteristicValueToMap( std::map<Characteristic, int> &columnNumberByCharacteristicMap,
	                                  std::map<int, std::string> &valuesByColumnNumber,
	                                  const Characteristic characteristicName, const CharacteristicValue characteristicValue) const {
		int columnNumberOfCharacteristic = columnNumberByCharacteristicMap[characteristicName];
		valuesByColumnNumber[columnNumberOfCharacteristic] = std::to_string(characteristicValue);
	}

	void addColumnNames(const std::map<Characteristic, int> &columnNumberByCharacteristicMap, csv::ofstream &os ) const {
		std::map<int, std::string> valuesByColumnNumber;
		for(auto &characteristicAndColumnNumberPair : columnNumberByCharacteristicMap){
			valuesByColumnNumber[characteristicAndColumnNumberPair.second] = characteristicAndColumnNumberPair.first;
		}
		std::vector<std::string> rowValues = createRowValuesVector(valuesByColumnNumber);
		writeOneRowToCsv(os, rowValues);
	}

};


#endif //WYKOPMAINDATAALANYZER_TOCSVEXPORTER_H
