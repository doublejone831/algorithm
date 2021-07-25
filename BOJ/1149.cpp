/*
DP -> 세개를 모두 더해가며 O(3N)으로 계산 마지막에 최솟값 비교
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	// 0 = R, 1 = G, 2 = B
	vector<vector<int>> cost(N+1,vector<int>(3,0));
	
	for (int i = 1; i < N + 1; i++) {
		int col_cost[3] = { 0 };
		cin >> col_cost[0] >> col_cost[1] >> col_cost[2];
		for (int j = 0; j < 3; j++) {
			cost[i][j] = col_cost[j];
		}
	}

	vector<vector<int>> temp(N + 1, vector<int>(3, 0));

	temp[0][0] = 0; temp[0][1] = 0; temp[0][2] = 0;

	for (int i = 1; i < N+1; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				temp[i][j] = min(temp[i - 1][1], temp[i - 1][2]) + cost[i][j];
			}
			else if(j == 1) {
				temp[i][j] = min(temp[i - 1][0], temp[i - 1][2]) + cost[i][j];
			}
			else {
				temp[i][j] = min(temp[i - 1][0], temp[i - 1][1]) + cost[i][j];
			}
		}
	}

	int answer = temp[N][0] < temp[N][1] ? (temp[N][0] < temp[N][2] ? temp[N][0] : temp[N][2]) : (temp[N][1] < temp[N][2] ? temp[N][1] : temp[N][2]);

	cout << answer;


}
