/***************************************************
결국 -또는 +를 기준으로 반대 부호인것들의 합이 기준값을 만족 하는지
1. -값 을 기준
2. +값 을 기준
점수와 해당점수를 가진 명수를 이용하면 더 적은 시간에 계산 가능 할듯
****************************************************/

#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int> &a, pair<int,int> &b){
   return a.first < b.first;
}

int BSearch(vector<pair<int,int>> v, int target,int low, int high) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (v[mid].first == target)
        return mid;
    else if (v[mid].first > target)
        return BSearch(v, target, low, mid - 1);
    else
        return BSearch(v, target, mid + 1, high);
}

int main(){
    int N, A;
    cin >> N;
    int Answer = 0;
    vector<pair<int, int>> All;
    int zerocount = 0;
    
    //입력
    for(int i = 0; i < N; i++){
        cin >> A;
        if(A == 0){
            zerocount += 1;
        }
        else{
            if (All.size() == 0) {
                All.push_back(make_pair(A, 1));
            }
            else {
                int index = BSearch(All, A, 0, All.size()-1);
                if (index == -1) {
                    All.push_back(make_pair(A, 1));
                }
                else {
                    All[index].second += 1;
                }

            }
            
        }
    }
    
    sort(All.begin(), All.end(), compare);
    
    
    if (zerocount > 2) {
        int fac = 1;
        for (int i = zerocount; i > 1; i--) {
            fac = fac * i;
        }
        Answer += (fac / 6);
    }
    
    
    if(zerocount != 0){
        for(int i = 0; i < All.size(); i++){
            int idx = BSearch(All, All[i].first, i, All.size()-1);
            if(idx = -1) continue;
            else Answer += zerocount * All[i].second * All[idx].second;     
        }
    }
    
    for(int i = 0; i < All.size(); i++){
        int object = abs(All[i].first);
        int upper = All.size()-1;
        int lower = i+1;
        if(lower > upper){
            continue;
        }
        if(lower == upper){
            if(All[lower].second > 1){
                if(abs(All[lower].first * 2) == object){
                    int fac = 1;
                    for (int j = All[lower].second; j > 1; j--) {
                        fac = fac * j;
                    }
                    Answer += All[i].second * (fac / 2);
                }
            }
            continue;
        }
        
        if(abs(All[lower].first + All[upper].first) == object){
            Answer += All[lower].second * All[upper].second * All[i].second;
        }
        else{
            if(abs(All[lower].first + All[upper].first) > object){
                upper--;
            }
            else{
                lower++;
            }
        }
        
    }
    
    
    cout << Answer;
    
}