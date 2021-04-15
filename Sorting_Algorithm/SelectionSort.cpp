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
**/