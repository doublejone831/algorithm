#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(){
    vector<int> answer;
    int MAX = 10000;
    char x;
    char arr[MAX];
    int probs;
    for(int i = 0; i < MAX; i++){
        cin >> x;
        if(x == '[' || x == ','){
            i--;
            continue;
        }
        if(x == ']'){
            probs = i;
            break;
        }
        else{
            arr[i] = x;
        }
    }
    
    char Student1[MAX];
    for(int j = 0; j < probs; j++ ){
        Student1[j] = (j+1)%5 + '0';
        if(Student1[j] == '0'){
            Student1[j] = '5';
        }

    }

    char Student2[MAX];
    int a = 1;
    for(int k = 0; k < probs; k++){
        if(k % 2 == 0){
            Student2[k] = '2';
        }
        else{
            if(a == 1){
                Student2[k] = '1';
                a++;
            }
            else if(a == 2){
                Student2[k] = '3';
                a++;
            }
            else if(a == 3){
                Student2[k] = '4';
                a++;
            }
            else if(a == 4){
                Student2[k] = '5';
                a = 1;
            }
        }

    }

    char Student3[MAX];
    for(int l = 0; l < probs; l++){
        if(l % 10 / 2 == 0){
            Student3[l] = '3';
        }
        else if(l % 10 / 2 ==1){
            Student3[l] = '1';
        }
        else if(l % 10 / 2 == 2){
            Student3[l] = '2';
        }
        else if(l % 10 / 2 == 3){
            Student3[l] = '4';
        }
        else{
            Student3[l] = '5';
        }
 
    }

    int point_1 = 0, point_2 = 0, point_3 = 0;
    
    for(int p = 0; p < probs ; p++){
        if(arr[p] == Student1[p]){
            point_1++;
        }
        if(arr[p] == Student2[p]){
            point_2++;
        }
        if(arr[p] == Student3[p]){
            point_3++;    
        }
    }

    int flag = 1;
    int p_max = point_1;
    while(true){
    if(p_max < point_2){
        p_max = point_2;
        flag = 2;
        if(p_max == point_3){
            flag = 6;
        }
        break;
    }
    if(p_max == point_2){
        flag = 4;
        if(p_max == point_3){
            flag = 7;
            
        }
        break;
    }
    if(p_max == point_3){
        flag = 5;
        break;
    }
    if(p_max < point_3){
        p_max = point_3;
        flag = 3;
        break;
    }
        break;
    }

    switch (flag){
        case 1:
            answer.push_back(1);
            break;
        case 2:
            answer.push_back(2);
            break;
        case 3:
            answer.push_back(3);
            break;
        case 4:
            answer.push_back(1);
            answer.push_back(2);
            break;
        case 5:
            answer.push_back(1);
            answer.push_back(3);
            break;
        case 6:
            answer.push_back(2);
            answer.push_back(3);
            break;
        case 7:
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
            break;
            
    }
    for(int i = 0; i < answer.size() ; i++){
        cout << answer[i] << " ";
    }
        
}