//
// Created by defacto on 23.09.15.
//

#include <test/help/Random.h>
#include <fstream>
#include "TempFile.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

const char * test::TempFile::getPath() {
	if( this->path == ""){
		createNewFile();
	}
	return this->path.c_str();
}

void test::TempFile::createNewFile() {
	std::stringstream ss;
	ss << Random::CreateRandomAlphanumericString() <<  ((strlen(extension_) != 0) ? "." : "") << extension_;

	string fileName = ss.str();
	this->path = std::string(("/tmp/"+fileName).c_str());
	fstream fs;
	fs.open(this->path.c_str(), ios::out);
	fs.close();
	std::cout << "FILE IS " << path << std::endl;
}

test::TempFile::~TempFile() {
//	if( remove( this->path ) != 0 ){
//		cerr << "Error while removing file with path " << this->path << endl;
//	}
}
