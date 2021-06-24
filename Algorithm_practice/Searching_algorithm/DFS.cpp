//깊이 우선 탐색
//맹목적으로 각노드를 탐색할때 사용
//stack이 사용 but 컴퓨터 자체가 구조적으로 stack을 사용하기 때문에 stack의 사용 없이 재귀로도 구현이 가능하다.
// 스택의 최상단 노드 확인 -> 최상단 노드에 방문하지 않은 인접 노드가 있다면 그 노드를 스택에 넣고 방문 처리, 방문 하지 않은 인접 노드가 럾다면 스택에서 최상단 노드 제거

#include<iostream>
#include<vector>

using namespace std;

int number = 7; //원소수 이용
int visit[7];//방문여부 파악
vector<int> a[8]; //인접 노드 저장

void DFS(int x){
    if(visit[x]) 
        return;
    visit[x] = true;
    cout << x << '\n';
    for(int i = 0; i < a[x].size(); i++){
        int y = a[x][i];
        DFS(y);
    }
}

int main(){
    a[1].push_back(2);
    a[2].push_back(1);
    
    a[1].push_back(3);
    a[3].push_back(1);
    
    a[2].push_back(3);
    a[3].push_back(2);
    
    a[2].push_back(4);
    a[4].push_back(2);
    
    a[2].push_back(5);
    a[5].push_back(2);
    
    a[4].push_back(5);
    a[5].push_back(4);
    
    a[3].push_back(6);
    a[6].push_back(3);
    
    a[3].push_back(7);
    a[7].push_back(3);
    
    a[6].push_back(7);
    a[7].push_back(6);
    
    DFS(1);
}