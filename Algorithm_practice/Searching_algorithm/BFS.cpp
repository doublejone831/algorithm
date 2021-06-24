//탐색시 너비를 우선으로 하여 탐색하는 알고리즘
//맹목적인 탐색시 유효, 최단경로 를 찾아주기도 함 ex)미로찾기
//queue를 이용 노드를 꺼냄, 꺼낸 노드에서 연결된 방문하지 않은 노드 방문 하며 큐에 삽입,
//root에서 가까운 순서대로 출력이 됨
//이 자체로는 큰 의미가 없고 다른 알고리즘에 적용되어 쓸 수 있어야 한다..
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7; // 원소의 갯수
int visit[7]; //방문 여부 확인
vector<int> a[8]; // 인접 정보를 저장하는 백터 배열 생성
//start는 시작점
void BFS(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true; // 시작 노드 방문 완료하였으므로 방문처리
    while(!q.empty()){
        int x = q.front(); // q에 앞부분 가져옴
        q.pop(); // 가져온것 제거
        cout << x << "\n";
        
        //연결된 노드들 방문
        for(int i = 0; i < a[x].size(); i++){
            int y = a[x][i]; 
            if(!visit[y]){
                q.push(y); //연결되었으면서, 방문하지 않은 노드들을 que에 입력
                visit[y] = true; //방문 처리
            }
        }
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
    
    BFS(1);
}