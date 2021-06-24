//Stack -> 후입 선출(LIFO) <--> Queue -> 선입 선출(FIFO)
/*stack은 container 가 아닌 container adaptor 로 기본적으로는 deque위에 기능
들을 제한하거나 얹어서 만든것*/
/*Stack is a container adaptor, meaning that it is implemented on top of some underlying container type. By default that underlying type is deque, but a different type may be selected explicitly.*/
//Stack 라이브러리 사용가능
#include <iostream>
#include <stack>
#include <deque> // 양방향 queue
#include <vector>
using namespace std;

int main(){
    stack<int> s; // stack생성
    stack<int> s2({1 , 2 , 3 , 4 , 5}); // 초기화된 stack 생성
    deque<int> d(5,10);
    stack<int> s3(d1); // deque를 복사해서 stack 생성
    stack<int, vector<int>> s4; // stack을 vector로 구현
    stack<int, deque<int>> s5; // stack을 deque로 구현
    
    
    s.push(7); //stack에 content 추가
    s.push(5); //stack에 content 추가
    s.size(); //원소수 반환
    s.empty(); //비어있는지 확인
    s.top(); // stack의 맨위의 content 반환 -> 5 return;
    s.pop(); //stack에서 content 제거 -> 5 제거
    
}