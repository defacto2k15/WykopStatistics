//
// Created by defacto on 24.09.15.
//

#include "OutFileAnalyzer.h"
#include <vector>
#include <algorithm>
#include "minicsv.h"
#include <stdexcept>
#include <test/exceptions/ColumnWithGivenNameNotFoundException.h>
#include "boost/algorithm/string.hpp"
#include "test/help/Algorithm.h"

unsigned long OutFileAnalyzer::getRowNumber() {
	makeSureDataIsLoaded();
	return rowsVector_.size();
}


bool OutFileAnalyzer::containsRowWithValues(std::vector<std::pair<std::string, std::string>> columnNameValuePairs) {
	auto it = std::find_if(begin(rowsVector_), end(rowsVector_), [&columnNameValuePairs, this]
			(std::vector<std::string>& rowValues){
				for( auto &pair : columnNameValuePairs ){
					auto columnIndex = getColumnIndex(pair.first);
					bool contains = rowValues.at(columnIndex) == pair.second;
					if(contains == false){
						return false;
					}
				}
				return true;
			});
	return it != end(rowsVector_);
}

void OutFileAnalyzer::makeSureDataIsLoaded() {
	if( this->rowsVector_.size() == 0){
		loadDataFromFile();
	}
}

void OutFileAnalyzer::loadDataFromFile() {
	std::fstream fs;
	fs.open(this->filePath_);
	if(!fs.is_open() ){
		std::stringstream ss;
		ss << "Cant open csv file of path "<<filePath_;
		throw std::runtime_error(ss.str());
	}

	std::string line;
	while((std::getline(fs, line))){
		std::vector<std::string> strs;
		boost::split(strs, line, boost::is_any_of(","));
		rowsVector_.push_back(strs);
	}
	setColumnNamesVector(rowsVector_);
}

void OutFileAnalyzer::setColumnNamesVector(std::vector<std::vector<std::string>> rowsVector) {
	columnNamesVector_ = rowsVector.back();
}

unsigned long OutFileAnalyzer::getColumnIndex(std::string columnName) {
	auto it = std::find( begin(columnNamesVector_), end(columnNamesVector_), columnName);
	if( it == end(columnNamesVector_)){
		throw ColumnWithGivenNameNotFoundException("Cant find column with name " + columnName);
	}
	return std::distance( begin(columnNamesVector_), it);
}

bool OutFileAnalyzer::containsColumns(std::vector<std::string> columnNames) {
	return help::contains_all(columnNames, columnNamesVector_);
}
