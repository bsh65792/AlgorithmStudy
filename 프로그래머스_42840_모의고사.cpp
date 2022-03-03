#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int rightQuantity[3] = {0};

    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0 ; i < answers.size() ; i++){
        if(one[i%5] == answers.at(i)){
            rightQuantity[0]++;
        }
        if(two[i%8] == answers.at(i)){
            rightQuantity[1]++;
        }
        if(three[i%10] == answers.at(i)){
            rightQuantity[2]++;
        }
    }
    int largestQuantity = -1;
    int largestIndex;
    
    for(int i = 0 ; i < 3 ; i++){
        printf("%d ", rightQuantity[i]);
    }
    
    for(int i = 2 ; i >= 0 ; i--){
        if(rightQuantity[i] > largestQuantity){
            largestQuantity = rightQuantity[i];
            largestIndex = i;
        }
    }
    
    for(int i = 0 ; i < 3 ; i++){
        if(rightQuantity[i] == largestQuantity){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
