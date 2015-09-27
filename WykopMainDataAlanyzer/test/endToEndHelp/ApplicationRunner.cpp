//
// Created by defacto on 24.09.15.
//

#include <exception>
#include <iostream>
#include <WykopMainDataAnalyzer.h>
#include <vector>
#include <bits/unique_ptr.h>
#include "ApplicationRunner.h"

bool ApplicationRunner::runWithParamerers(std::vector<const char *> list) {
	try{
		std::unique_ptr< const char*> argv(new const char*[list.size()+1]);
		int i = 1;
		for( auto it = list.begin(); it != list.end(); it++){
			std::cout << " " << i << "  " << *it << std::endl;
			(argv.get())[i] = *it;
			i++;
		}
		argv.get()[0] = "ApplicationName - should not be used";
		wykopMainDataAnalyzerMain(list.size()+1, argv.get());
	}catch (std::exception &e){
		std::cout << " Caught unexpected exception "  << "  " << e.what() << std::endl;
		return false;
	}
	return true;
}
