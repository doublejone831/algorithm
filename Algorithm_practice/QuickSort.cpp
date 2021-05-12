#include <iostream>

const int N = 10;

//Swap index a and index b data in arr
void Swap(int* arr, int a, int b){
    int temp;
    
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void QuickSort(int* data, int start, int end){
    if(start >= end){ // 원소가 한개인 경우
        return;
    }
    
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    while(i <= j){ // i 와 j가 엇갈릴때 까지 반복
        while(data[i] <= data[key]){ // i가 key 값보다 큰값을 만날때 까지 오른쪽으로
            i++;
        }
        while(data[j] >= data[key] && j > start){ // j 가 키값보다 작은 값을 만날때까지 반복
            j--;
        }
        if( i > j){ //엇갈린 상태이면 키 값과 교체
            Swap(data,j,key);
        }
        else{ //
            Swap(data,i,j);
        }
    }
    
    QuickSort(data, start, j-1);
    QuickSort(data, j+1, end);
}

int main(){
    int arr[N] = {10, 5, 4, 6, 7, 1, 3, 8, 2, 9};
    int Size = sizeof(arr)/sizeof(int);
    
    QuickSort(arr , 0, N);

    for(int i = 0; i < Size; i++){
        std::cout << arr[i] << " ";
    }
}