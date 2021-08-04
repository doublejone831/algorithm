#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> EulerSieve(int N) {
	//소수 컨테이너
	vector<int> primes;
	
	//N의 크기를 가지는 원본 숫자벡터 생성
	vector<int> original;
	original.reserve(N);
	for (int i = 2; i < N; i++) {
		original.push_back(i);
	}
	while (original.size() > 0) {
		vector<int> temp;
		temp.reserve(original.size());

		//원본 리스트의 (0번 인덱스 * 모든 원본의 값)을 새 리스트에 등록
		//range based for문
		for (const auto& it : original) {
			temp.push_back(it * original[0]);
		}

		//새 리스트에 값이 있는 원본 리스트 제거
		for (auto it = temp.begin(); it != temp.end(); ) {
			vector<int>::iterator FindIndex = find(original.begin(), original.end(), *it);
			if (FindIndex != original.end()) {
				original.erase(FindIndex);
			}
			else {
				it++;
			}
		}

		//원본의 0번쨰 인덱스를 소수로 등록하고 제거
		if (original.size() > 0) {
			primes.push_back(original[0]);
			original.erase(original.begin());
		}
	}
	return primes;
}

vector<bool> EratostenesSieve(int N) {
	vector<bool> prime(N+1, true);

	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= N; i++) {
		if (prime[i]) continue;

		for (int j = 2 * j; j <= N; j += 1) {
			prime[j] = false;
		}
	}
}
