#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

//1. operations의 수에 맞게끔 반복문을 돈다.
//2. 해당 반복시점의 명령어 첫 글자를 저장한다.
//3. 새 string 타입 변수 지정 -> 두 칸 앞으로 당긴 후 stoi로 int 형태로 변환한다.
//4. 명령어가 I라면 우선순위 큐에 삽입 후 sort
//5. 명령어가D 이면서, int가 1이면 우선순위 큐의 맨 뒤에 값 삭제


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> q;
    vector<int> v;
    
    char operationCode;
    string numberString = "";
    int numberInt;
    
    for(int i = 0 ; i < operations.size() ; i++){
        numberString = "";
            
        operationCode = operations.at(i)[0];
        
        for(int j = 2 ; j < operations.at(i).length(); j++){
            numberString = numberString + operations.at(i)[j];
        }
        numberInt = stoi(numberString);
        
        if((int)operationCode == (int)'I'){
            v.push_back(numberInt);
        } else if((int)operationCode == (int)'D'){
            if(v.size() > 0){
                if(numberInt == 1){
                    v.erase(v.begin() + (v.size() - 1));
                } else if(numberInt == -1){
                    v.erase(v.begin());
                }
            }
        }
        
        sort(v.begin(), v.end());
        
        
    }
    if(v.size() > 0){
        answer.push_back(v.at(v.size() - 1));
        answer.push_back(v.at(0));
    } else{
        answer.push_back(0);
        answer.push_back(0);
    }

    
    return answer;
}
