//queue -> FIFO
/*Queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are pushed into the "back" of the specific container and popped from its "front". It specifically designed to operate in a FIFO context (first-in first-out), where elements are inserted into one end of the container and extracted from the other.*/
/* deque와 list 컨테이너 위에 implement*/
#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q1; // 비어있는 queue생성
    queue<int> q2({1, 2, 3, 4, 5}); //초기화된 queue생성
    deque<int> dq1 = {1,2,3,4};
    queue<int> q1(dq1); //deque를 복사하여 queue 생성
    
    
}