#include <iostream>

//Swap index a and index b data in arr
void Swap(int* arr, int a, int b){
    int temp;
    
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void InsertionSort(int* arr, int Size){
    if(Size > 1){
        int key;
        int empty;
        for(int i = 1; i < Size ; i++){
            key = arr[i];
            for(int j = i-1; j >= 0 && arr[j] > key; j--){
                arr[j+1] = arr[j];
                arr[j] = key;
            }
            
        }
    }
}

int main(){
    int arr[10] = {10, 5, 4, 6, 7, 1, 3, 8, 2, 9};
    int Size = sizeof(arr)/sizeof(int);
    
    InsertionSort(arr , Size);
    
    for(int i = 0; i < Size; i++){
        std::cout << arr[i] << " ";
    }
}