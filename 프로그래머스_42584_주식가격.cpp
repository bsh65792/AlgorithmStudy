#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    bool find = false;
    
    for(int i = 0 ; i < prices.size() ; i++){
        find = false;
        for(int j = i + 1 ; j < prices.size() ; j++){
            if(prices.at(i) > prices.at(j)){
                answer.push_back(j - i);
                find = true;
                break;
            }
        }
        if(find == false){
            answer.push_back(prices.size() - 1 - i);
        }
    }
    
    
    return answer;
}
