#include <string>
#include <vector>

using namespace std;

int sumMap[500][500] = {0, };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    if(triangle.size() == 1) return triangle[0][0];
    
    sumMap[0][0] = triangle[0][0];
    
    for(int i = 1 ; i < triangle.size() ; i++){
        
        sumMap[i][0] = triangle[i][0] + sumMap[i - 1][0];
        
        for(int j = 1 ; j < triangle[i].size() - 1 ; j++){
            if(sumMap[i - 1][j - 1] > sumMap[i - 1][j])
                sumMap[i][j] = sumMap[i - 1][j - 1] + triangle[i][j];
            else
                sumMap[i][j] = sumMap[i - 1][j] + triangle[i][j];
        }
        sumMap[i][triangle[i].size() - 1] = triangle[i][triangle[i].size() - 1]
                                          + sumMap[i - 1][triangle[i].size() - 2];
    }
    
    int largestNumber = 0;
    
    for(int i = 0 ; i < triangle.size() ; i++){
        if(sumMap[triangle.size() - 1][i] > largestNumber)
            largestNumber = sumMap[triangle.size() - 1][i];
    }
    

    answer = largestNumber;
    return answer;
}
