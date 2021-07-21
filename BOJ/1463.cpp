// bottom - up 방식 사용하는 문제
//그러면 O(n)에 해결 가능
#include <iostream>


using namespace std;

int arr[1000001];

int min(int a, int b){
    return (a < b) ? a : b;
}

int main(){
    arr[0] = 0;
    arr[1] = 0;
    int N;
    cin >> N;
    for(int i = 2; i <= N; i++){
        arr[i] = arr[i-1] + 1;
        if(i % 2 == 0){
            arr[i] = min(arr[i/2] + 1, arr[i]);
        }
        if(i % 3 == 0){
            arr[i] = min(arr[i/3] + 1, arr[i]);
        }
        /*
        if (i % 3 == 0){
            arr[i] = min(arr[i/3],arr[i-1]) + 1;
        }
        else if(i % 2 == 0){
            arr[i] = min(arr[i/2],arr[i-1]) + 1;
        }
        else{
            arr[i] = arr[i-1] + 1;
        }*/
    }
    
    cout << arr[N];
    return 0;
}