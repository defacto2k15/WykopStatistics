//
// Created by defacto on 23.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_TEMPFILE_H
#define WYKOPMAINDATAALANYZER_TEMPFILE_H

#include "cstdio"

namespace test {
	class TempFile {
	private:
		std::string path;
		const char * const extension_;
	public:
		TempFile(const char *fileExtension = "") : extension_(fileExtension){};
		const char * getPath();
		void createNewFile();
		~TempFile();

		TempFile (const TempFile& other) = delete;
		TempFile (TempFile&& other) = delete;
		TempFile& operator=(TempFile&) = delete;
		TempFile& operator=(TempFile&&) = delete;

	};
}


#endif //WYKOPMAINDATAALANYZER_TEMPFILE_H
