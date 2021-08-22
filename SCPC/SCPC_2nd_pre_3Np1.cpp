#include <iostream>
#include <cmath>
#include <algorithm>
typedef unsigned long long  ull;

using namespace std;


ull solution(int K, ull cur) {
    //escape
    if (K == 0) {
        return cur;
    }

    ull temp = solution(K - 1, cur * 2);

    if ((cur - 1) % 3 == 0 && (cur - 1) / 3 % 2 == 1 && cur > 5) {
        temp = min(temp, solution(K - 1, (cur - 1) / 3));
    }
    return temp;
}

int main() {
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++) {
        int I;
        cin >> I;
        cout << fixed;
        cout.precision(0);

        ull MAX = (ull)1 << I;
        cout << "Case #" << C << endl;
        cout << solution(I, 1) << " " << MAX << endl;

    }
}
