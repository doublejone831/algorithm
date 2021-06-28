/*******************************************************
//////////////////백준 1946번 신입사원////////////////////
*******************************************************/
/* 문제 이해:
적어도 하나가 다른사람보다 뛰어나야함 -> 어느 부문 1등의 다른 점수보다는 높아야함
그럼 서류 1등의 면접 점수보다 높은 등수 인사람들 중에서 뽑혀야 하며
그 사람은 면접 1등의 서류 점수 보다 높아야한다.
*/
/*
풀이 구상:
입력된 자료들을 pair형태로 저장 -> 정렬 시 서류 순서대로 정렬
그 후 면접 1등을 찾아내서 서류 1등 부터 면접 1등 사이의 값의 갯수 리턴 
--> 정렬 nlogn + 탐색 바이너리 서치로 logn -> nlogn
--> 하지만 서류 순으로 정렬 이되어있으므로 바이너리 서치 불가능 -> linear search필요
+ --> 그냥 저렇게 하면 서류 1등과 면접 1등 사이에 있는 값중에 둘다 작은 새로운 min값이 생기며 사이에 있어도 포함이 되지 않는 경우의 수가 생길수 있어 second의 min값은 계속 갱신이 필요함
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare (pair<int,int> &a, pair<int,int> &b){
    return a.first < b.first; // 부등호 바꾸면 내림차순
}


int main(){
    int T, N, paper, interview ;
    cin >> T;
    vector<pair<int, int>> Candidate;
    for(int i = 0; i < T; i++){
        cin >> N;
        int idx, answer = 0;
        for(int j = 0; j < N; j++){
            cin >> paper >> interview;
            pair<int, int> temp = pair<int, int>(paper, interview);
            Candidate.push_back(temp);
        }
        sort(Candidate.begin(), Candidate.end(), compare);
        for(idx = 0; Candidate[idx].second != 1; idx++){
            continue;
        }
        int min_idx = 0;
        for(int j = 0; j <= idx ; j++){
            if(Candidate[j].second <= Candidate[min_idx].second){
                min_idx = j;
                answer++;
            }
        }
        cout << answer << "\n";
        Candidate.clear();
    }    
}