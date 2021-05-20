//heap tree structure 이용

#include <iostream>
#include <vector>

//Swap index a and index b data in arr
void Swap(int* arr, int a, int b){
    int temp;
    
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

//배열을 Max heap으로
void make_heap(int* arr,int size){ 
    //모든 노드 검사
    for(int i = 1; i < size; i++){
        int cur = i;
        // 현재부터 0번까지 거슬러올라가며 큰것을 상위로 옮김
        do{
            int root = (cur - 1) / 2; // 루트는 자기자신 -1 / 2로 구해짐
            if(arr[root] < arr[cur]){
                Swap(arr, root, cur); // 만약 루트가 자신보다 작을시 루트와 교환
            }
            cur = root;
            
        }while(cur != 0); // 현재 노드가 전체 힙의 루트노드에 도달시 탈출
    }
}
// Max heap으로 만들기
void Max_heap(int* arr,int size,int root){
    // 리프노드일경우 종료
    if(root * 2 +1 >= size ){
        return;
    }
    int cur = root * 2 + 1;
    
    if(cur + 1 <  size){
        if(arr[cur] < arr[cur +1]){
        cur++;
        }
    }
    if(arr[root] < arr[cur]){
        Swap(arr, root, cur);
    }
    Max_heap(arr, size, cur);
    
}

void heapsort(int* arr, int size){
    for(int i = 0; i < size; i++){
        Swap(arr, 0, size - i - 1); // 모든 heap의 루트인 0번과 힙의 맨 마지막과 교환
        Max_heap(arr, size - i - 1, 0); // 기존 heap의 맨 마지막을 빼고 나머지 부분을 다시 heap을 만족 시키게 변경
    }
    
}

int main(){
    int arr[10] = {10, 5, 4, 6, 7, 1, 3, 8, 2, 9};
    int Size = sizeof(arr)/sizeof(int);
    make_heap(arr , Size);
    heapsort(arr , Size);
    
    for(int i = 0; i < Size; i++){
        std::cout << arr[i] << " ";
    }
}

