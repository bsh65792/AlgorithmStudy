#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cantSeeNumber = 0;
    int rightNumber = 0;
    
    int largestRightNumber;
    int smallestRightNumber;
    
    for(int i = 0 ; i < lottos.size() ; i++){
        //로또 번호가 보이는 부분일 때
        if(lottos.at(i) != 0){
           for(int j = 0 ; j < win_nums.size() ; j++){
                //당첨일 경우
               if(lottos.at(i) == win_nums.at(j)){
                   win_nums.erase(win_nums.begin() + j);
                   j--;
                   break;
               }
            }     
        }else{
            cantSeeNumber++;
        }
    }
    
    largestRightNumber = 6 - (win_nums.size() - cantSeeNumber);
    smallestRightNumber = 6 - win_nums.size();
    
    
    if(largestRightNumber <= 1){
        answer.push_back(6);
    }else{
        answer.push_back(7-largestRightNumber);
    }
        
        
        
    if(smallestRightNumber <= 1){
        answer.push_back(6);
    }else{
        answer.push_back(7-smallestRightNumber);
    }
    
    
    return answer;
}
