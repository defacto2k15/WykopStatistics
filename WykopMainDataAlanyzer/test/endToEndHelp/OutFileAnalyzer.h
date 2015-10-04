//
// Created by defacto on 24.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_OUTFILEANALYZER_H
#define WYKOPMAINDATAALANYZER_OUTFILEANALYZER_H

#include <map>
#include <vector>
#include <initializer_list>

class OutFileAnalyzer {
	std::vector<std::vector<std::string>> rowsVector_;
	std::vector<std::string> columnNamesVector_;
	const char * filePath_;
public:
	OutFileAnalyzer(const char *filePath) : filePath_(filePath){};

	unsigned long getRowNumber();

	bool containsRowWithValues(std::vector<std::pair<std::string,std::string>> columnNameValuePairs);

	bool containsColumns(std::vector<std::string> columnNames);

	void loadDataFromFile();
private:
	void makeSureDataIsLoaded();

	void setColumnNamesVector(std::vector<std::vector<std::string>> rowsVector);
	unsigned long getColumnIndex(std::string columnName);
};


#endif //WYKOPMAINDATAALANYZER_OUTFILEANALYZER_H
