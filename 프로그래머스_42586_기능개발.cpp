#include <string>
#include <vector>
#include <list>

using namespace std;

int checkAlreadyFinished[100] = {0};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> daysOfProgresses;
    
    
    
    for(int i = 0 ; i < progresses.size() ; i++){
        int days = 0;
        
        days = (int)((100 - progresses.at(i))/speeds.at(i)); //몫을 저장.
        
        //작업을 딱 맞게 끝내지 못할 경우 몫에다가 + 1을 해야 한다.
        if((100 - progresses.at(i))%speeds.at(i) != 0){
            days++;
        }
        daysOfProgresses.push_back(days);
    }
    
    for(int i = 0 ; i < daysOfProgresses.size() ; i++){
        int sameDayFinishQuantity = 0;
        
        if(checkAlreadyFinished[i] == 1){
            //이미 업무가 끝난 것이라면
            continue;
        }
        else
        {
            sameDayFinishQuantity++; // 자신의 작업량을 더해준다.
            checkAlreadyFinished[i];
            
            //다른 작업을 더해준다.
            for(int j = i + 1 ; j < daysOfProgresses.size() ; j++){
                if(daysOfProgresses.at(i) >= daysOfProgresses.at(j)){
                    sameDayFinishQuantity++;
                    checkAlreadyFinished[j] = 1;
                } else{
                    break;
                }
            }
            answer.push_back(sameDayFinishQuantity);
        }
        
    }
    

    
    //맨 처음부터 하나씩 검사하기.
    
    
    return answer;
}
