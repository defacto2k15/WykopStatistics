//
// Created by defacto on 25.09.15.
//

#ifndef WYKOPMAINDATAALANYZER_ALGORITHM_H
#define WYKOPMAINDATAALANYZER_ALGORITHM_H
namespace  help {
	template<typename T>
	bool contains_all(std::vector<T> c1, std::vector<T> c2) {
		std::vector<T> tempC1(c1);
		std::vector<T> tempC2(c2);
		std::sort(begin(tempC1), end(tempC1));
		std::sort(begin(tempC2), end(tempC2));

		std::vector<T> out(c1.size()+c2.size());
		auto it = std::set_intersection(begin(tempC1), end(tempC1),
		                                begin(tempC2), end(tempC2), begin(out));
		out.resize(it - begin(out));
		return out == tempC1;
	};
}

#endif //WYKOPMAINDATAALANYZER_ALGORITHM_H
