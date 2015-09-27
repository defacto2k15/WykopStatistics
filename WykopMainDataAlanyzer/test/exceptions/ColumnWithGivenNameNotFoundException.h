//
// Created by defacto on 25.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_COLUMNWITHGIVENNAMENOTFOUNDEXCEPTION_H
#define WYKOPMAINDATAALANYZER_COLUMNWITHGIVENNAMENOTFOUNDEXCEPTION_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

class ColumnWithGivenNameNotFoundException : public std::runtime_error {
public:
	ColumnWithGivenNameNotFoundException(std::string text) : std::runtime_error(
			std::string("ColumnWithGivenNameNotFoundException happened: ") + text) {
	}

	ColumnWithGivenNameNotFoundException() : ColumnWithGivenNameNotFoundException("") { }
};


#endif //WYKOPMAINDATAALANYZER_COLUMNWITHGIVENNAMENOTFOUNDEXCEPTION_H
