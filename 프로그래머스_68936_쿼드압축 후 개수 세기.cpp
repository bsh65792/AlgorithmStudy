#include <string>
#include <vector>

using namespace std;

void CheckNumber(int startY, int startX, int endY, int endX);

vector<vector<int>> arr;
int zeroCount = 0;
int oneCount = 0;



vector<int> solution(vector<vector<int>> arrTemp) {
    arr = arrTemp;
    vector<int> answer;
    
    CheckNumber(0, 0, arrTemp.size() - 1, arrTemp.size() - 1);
    
    answer.push_back(zeroCount);
    answer.push_back(oneCount);
    
    return answer;
}


void CheckNumber(int startY, int startX, int endY, int endX){

    int number = arr[startY][startX];
    
    if(startY >= endY || startX >= endX){
        if(number == 0) zeroCount++;
        else if(number == 1) oneCount++;
        return;
    }
    //printf("%d, %d, %d, %d\n", startY, startX, endY, endX);
    
    for(int i = startY ; i <= endY ; i++){
        for(int j = startX; j <= endX ; j++){
            if(number != arr[i][j]){
                CheckNumber(startY, startX, startY + (endY - startY) / 2, startX + (endX - startX) / 2);
                CheckNumber(startY, startX + (endX - startX) / 2 + 1 , startY + (endY - startY) / 2, endX);
                CheckNumber(startY + (endY - startY) / 2 + 1, startX, endY, startX + (endX - startX) / 2);
                CheckNumber(startY + (endY - startY) / 2 + 1, startX + (endX - startX) / 2 + 1, endY, endX);
                return;
            }
        }
    }
    
    if(number == 0) zeroCount++;
    else if(number == 1) oneCount++;
    
    
}
