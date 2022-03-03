#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

set<string> gemSet;
unordered_map<string, int> gemMap;
vector<int> answer;
int gemQuantity = 0;
int iter_first = 0;
int iter_rear = 0;
int interval;

int answerFirst;
int answerRear;

vector<int> solution(vector<string> gems) {
    
    for(int i = 0 ; i < gems.size() ; i++){
        gemSet.insert(gems[i]);
        if(gemSet.size() > gemQuantity){
            gemQuantity = gemSet.size();
            iter_rear = i;
        }
    }
    
    interval = iter_rear - iter_first;
    answerFirst = iter_first + 1;
    answerRear = iter_rear + 1;
    
    for(int i = iter_first ; i <= iter_rear; i++){
        gemMap[gems[i]]++;
    }
    
    while(true){
        
        if(gemMap[gems[iter_first]] == 1){
            iter_rear++;
            if(iter_rear == gems.size()) break;
            gemMap[gems[iter_rear]]++;
        }else{
            gemMap[gems[iter_first]]--;
            iter_first++;
        }
        
        if(iter_rear - iter_first < interval){
            interval = iter_rear - iter_first;
            answerFirst = iter_first + 1;
            answerRear = iter_rear + 1;
        }
    }
    
    
    answer.push_back(answerFirst);
    answer.push_back(answerRear);
    
    
    return answer;
}
