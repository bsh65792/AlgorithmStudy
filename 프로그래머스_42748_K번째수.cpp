#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//1. 커맨드 갯수많큼 반복.
//2. 

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> arrayTemp;
    
    for(int i = 0 ; i < commands.size() ; i++){
        arrayTemp.clear();
        
        for(int j = (commands.at(i).at(0) - 1) ; j <= (commands.at(i).at(1) - 1) ; j++){
            arrayTemp.push_back(array.at(j));
        }
        
        if(arrayTemp.size() > 0){
            sort(arrayTemp.begin(), arrayTemp.end());
        }
        answer.push_back(arrayTemp.at(commands.at(i).at(2) - 1));
        
    }
    
    
    
    
    return answer;
}
