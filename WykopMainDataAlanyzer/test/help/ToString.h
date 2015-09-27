//
// Created by defacto on 25.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_TOSTRING_H
#define WYKOPMAINDATAALANYZER_TOSTRING_H

#include <string>
#include "boost/algorithm/string/replace.hpp"

namespace help {

	template<typename T> std::string to_String(T elem);
	void addIndent(std::string &str);

	template<typename T>
	class ToStringConventer {
	public:
		static std::string to_String_internal(T element) {
			return std::to_string(element);
		}
	};

	template<>
	class ToStringConventer<std::string> {
	public:
		static std::string to_String_internal(std::string str){
			return str;
		}
	};

	template< typename T, typename U>
	class ToStringConventer<std::pair<T, U> > {
	public:
		static std::string  to_String_internal(std::pair<T,U> pair){
			std::stringstream ss;
			ss << " pair 1: " << to_String(pair.first) << "  2: " << to_String(pair.second) << " ";
			return ss.str();
		}
	};

	template<typename T>
	class ToStringConventer<std::vector<T>> {
	public:
		static std::string to_String_internal(std::vector<T> vec) {
			std::stringstream ss;
			int i = 0;
			ss << std::endl <<  "Vector of " << vec.size() << " elements" << std::endl;
			for (auto &element : vec) {
				ss << "[" << i << "]" << "  " << to_String(element) << " " << std::endl;
				i++;
			}
			return ss.str();
		}
	};

	template<typename T>
	std::string to_String(T elem) {
		auto str = ToStringConventer<T>::to_String_internal(elem);
		addIndent(str);
		return str;
	}

	void addIndent(std::string &str){
		boost::replace_all(str, "\n", "\n\t");
		str.insert(0,"\t");
	}
}

#endif //WYKOPMAINDATAALANYZER_TOSTRING_H
