//프로그래머스 정렬 중 h index문제 42747
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    int h = 0, n;
    n = citations.size();
    sort(citations.begin(), citations.end(), desc); //내림차순 정렬
    for(int i = 0; i < n; i ++){
        if(citations[0] == 0){ // 0,0,0 같이 인용이 한번도 안된 논문들만 있는경우
            break;
        }
        if(citations[i] >= i+1){ // i번째 원소가 i+1보다 큰경우 그 값을 임시로 h에 저장
            h = i+1;
            continue;
        }
        else{
            break; // i번째 원소가 i+1보다 작아지는 경우 기존의 h로 끝냄
        }
    }
    
    answer = h;
    
    return answer;
}

int main(){
    vector<int> citations = {1,2,3,4,5,6};
    
    
    cout << solution(citations);
}