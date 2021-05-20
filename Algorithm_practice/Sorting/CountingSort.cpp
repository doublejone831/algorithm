/** 
CountingSort -> 범위 조건이 있는 경우에 한해서 O(N)만족하는 정렬 알고리즘
크기를 기준으로 갯수만 세기만 하는 알고리즘 --> 여태까지 하던 알고리즘들은 자리를 변경하여 주는 알고리즘
정렬하는 데이터의 크기에 매우 의존하는 알고리즘
**/

#include <iostream>
#include <vector>


std::vector<int> CountingSort(int* arr, int Max, int Size){
    std::vector<int> count;
    for(int i = 0; i < Max; i++){
        count.push_back(0);
    }
    for(int i = 0; i < Size; i++){
        count[arr[i] - 1]++;
    }
    return count;
}

int main(){
    const int max = 5;
    int arr[30] = {
        1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
        3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
        3, 1, 4, 3, 5, 1, 2, 1, 1, 1
    };
    int Size = sizeof(arr)/sizeof(int);
    std::vector<int> count = CountingSort(arr, max, Size);
    for(int i = 0; i < count.size(); i++){
        for(int j = 0; j < count[i]; j++){
            std::cout << i +1 << " ";
        }
    }
    
    return 0;
}