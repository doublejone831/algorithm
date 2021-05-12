/**#include <iostream>

//Swap index a and index b data in arr
void Swap(int* arr, int a, int b){
    int temp;
    
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void BubbleSort(int* arr, int Size){
    int cur;
    for(int i = Size - 1; i >0; i--){
        cur = 0;
        for(int j = 1; j <= i; j++ ){
            if(arr[cur] > arr[j]){
                Swap(arr,cur,j);
            }
            cur = j;
        }
    }
}

int main(){
    int arr[10] = {10, 5, 4, 6, 7, 1, 3, 8, 2, 9};
    int Size = sizeof(arr)/sizeof(int);
    
    BubbleSort(arr , Size);
    
    for(int i = 0; i < Size; i++){
        std::cout << arr[i] << " ";
    }
}**/