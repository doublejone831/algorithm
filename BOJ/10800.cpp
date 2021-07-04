#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Ball{
    int Colors;
    int Size;
    int index;
    int Sum = 0;
};

bool compare(Ball &a, Ball &b){
    if(a.Size == b.Size){
        return a.Colors < b.Colors;
    }
    return a.Size < b.Size;
}

    
int main(){
    int N;
    
    cin >> N;
    
    vector<Ball> Balls;
    for (int i = 0; i < N; i++){
        int C, S;
        cin >> C >> S;
        Ball B;
        B.Colors = C;
        B.Size = S;
        B.index = i;
        Balls.push_back(B);
    }
    sort(Balls.begin(), Balls.end(), compare);
    
    int arr[200001];
    vector<int> colors(N+1,0);
    
    int wholeSum = Balls[0].Size;
    colors[Balls[0].Colors] += Balls[0].Size;
    
    int SameSize = Balls[0].Size;; // sum of same size
    int SSSC = Balls[0].Size;// sum of SameSize sameColors
    int col = Balls[0].Colors;// store color of SSSC
    for(int i = 1; i < N; i++){
        if(Balls[i].Size != Balls[i-1].Size){
            SameSize = 0;
            SSSC = 0;
              
        }
        else{
            if(Balls[i].Colors != Balls[i-1].Colors){
                SSSC = 0;
            } 
        }
        
        Balls[i].Sum = wholeSum - colors[Balls[i].Colors]  - SameSize + SSSC;
        
        wholeSum += Balls[i].Size;
        colors[Balls[i].Colors] += Balls[i].Size;

        SSSC += Balls[i].Size;
        col = Balls[i].Colors;
        
        SameSize += Balls[i].Size;
        
        
        
    }
    for(int i = 0; i < N; i++){
        arr[Balls[i].index] = Balls[i].Sum;
    }
    for(int i = 0; i < N ; i++){
        cout << arr[i] << "\n";
    }
    
}