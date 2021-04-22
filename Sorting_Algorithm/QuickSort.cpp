#include <iostream>

//Swap index a and index b data in arr
void Swap(int* arr, int a, int b){
    int temp;
    
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void Partition(int* arr, int )

void QuickSort(int* arr, int Size){

}

int main(){
    int arr[10] = {10, 5, 4, 6, 7, 1, 3, 8, 2, 9};
    int Size = sizeof(arr)/sizeof(int);
    
    SelectionSort(arr , Size);

    for(int i = 0; i < Size; i++){
        std::cout << arr[i] << " ";
    }
}