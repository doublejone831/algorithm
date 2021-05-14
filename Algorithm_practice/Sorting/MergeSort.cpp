#include <iostream>


// Merge Sort -> NlogN in every case
int sorted[10]; // 불필요한 메모리 사용을 줄임


void Merge(int* arr, int m, int middle, int n){ // m = start, n = end
    int i = m, j = middle +1 , k = m;
    //작은 순서대로 배열네 삽입
    while(i <= middle && j <= n){
        if(arr[i] <= arr[j]){
            sorted[k] = arr[i];
            i++;
        }
        else{
            sorted[k]= arr[j];
            j++;
        }
        k++;
    }
    // 남은 데이터 삽입
    if(i >middle){
        for(int t = j; t <= n; t++){
            sorted[k] = arr[t];
            k++;
        }
    }
    else{
        for(int t = i; t <= middle; t++){
            sorted[k] = arr[t];
            k++;
        }
    }
    //정렬된 배열을 실제 배열에 삽입
    
    for(int t = m; t <= n; t++){
        arr[t] = sorted[t];
    }
    for(int i = 0; i < 10; i++){
        std::cout << sorted[i] << " ";
    }
        std::cout << "\n";
}

void MergeSort(int* arr, int m, int n){
    if(m < n){
        int middle = (n+m)/2;
        
        MergeSort(arr,m, middle);
        MergeSort(arr, middle+1, n);
        Merge(arr,m,middle,n);
    }
}

int main(){
    int arr[10] = {10, 5, 4, 6, 7, 1, 3, 8, 2, 9};
    int Size = sizeof(arr)/sizeof(int);
    
    MergeSort(arr , 0, Size-1);
    
    for(int i = 0; i < Size; i++){
        std::cout << arr[i] << " ";
    }
}