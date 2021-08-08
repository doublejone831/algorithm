#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool Is_Penlindrome(int N) {
    string S1 = to_string(N);
    string S2 = S1;
    reverse(S2.begin(), S2.end());

    if (S1 == S2) {
        return true;
    }
    else {
        return false;
    }
}

bool Is_Prime(int N) {
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >>  b;
    if (b > 10000000) {
        b = 10000000;
    }
    for (int i = a; i <= b; i++) {
        if (Is_Penlindrome(i)) {
            if (Is_Prime(i)) {
                cout << i << "\n";
            }
        }
    }

    cout << -1;
}
