#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <map>
//MITライセンス　です。

typedef std::vector<std::int64_t> DType;

template<class Container>
 typename Container::value_type MakeHoge3(const Container& D) {
	std::map < Container::value_type, std::uintmax_t> M;

	for (auto& o : D) {
		M[o]++;
	}
	for (auto& o : M) {
		if (o.second == 1) {
			return o.first;
		}
	}
	return Container::value_type(-1);
}
/** /

typedef std::map<std::int64_t, std::uint64_t> MType;

std::int64_t MakeHoge2(const DType& D) {
	MType M;

	for (auto& o : D) {
		M[o]++;
	}
	for (auto& o : M) {
		if (o.second == 1) {
			return o.first;
		}
	}
	return -1;

}
/**/

/** /
DType::value_type MakeHoge(DType D) {

	std::sort(D.begin(), D.end());
	std::size_t i = 0;
		for (i = 1; i < D.size() - 1; i++) {
		if (D[i - 1] != D[i]) {
			if (D[i] == D[i + 1])continue;

			return D[i];
		}
	}
	if (D[i] != D[i - 1])return D[i];
	return -1;
}
/**/
int main() {
	DType D = { 1,1,1,1,2,2,2,3,3,4 };
	std::cout << MakeHoge3(D) << std::endl;
	D = DType{ 1,2,3,4,5,5,4,3,2,1 };
	std::cout << MakeHoge3(D) << std::endl;
	D = DType{ 3,1,4,1,5,9,2,6,5,3,5 };
	std::cout << MakeHoge3(D) << std::endl;
	return 0;
}

