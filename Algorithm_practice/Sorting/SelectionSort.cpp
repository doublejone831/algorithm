/**#include <iostream>

//Swap index a and index b data in arr
void Swap(int* arr, int a, int b){
    int temp;
    
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void SelectionSort(int* arr, int Size){
    int Min_idx;
    
    for(int i = 0; i < Size ; i++){
        Min_idx = i;
        for(int j = i+1 ; j < Size ; j++){
            if(arr[Min_idx] > arr[j]){
                Min_idx = j;
            }
        }
        if(Min_idx != i){
            Swap(arr,Min_idx,i);
        }
    }
}

int main(){
    int arr[10] = {10, 5, 4, 6, 7, 1, 3, 8, 2, 9};
    int Size = sizeof(arr)/sizeof(int);
    
    SelectionSort(arr , Size);

    for(int i = 0; i < Size; i++){
        std::cout << arr[i] << " ";
    }
}**/