#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> temp;
    
    
    for(int i = 0 ; i < participant.size() ; i++){
        temp[participant.at(i)]++;
    }
    for(int i = 0 ; i < completion.size() ; i++){
        temp[completion.at(i)]--;
    }
    
    for(int i = 0 ; i < participant.size() ; i++){
        if(temp[participant.at(i)] != 0){
            answer = answer + participant.at(i);
            break;
        }
    }
    
    
    return answer;
}
