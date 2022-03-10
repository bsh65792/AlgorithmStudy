#include <string>
#include <vector>

using namespace std;

int map[101][101] = {0, };

int solution(int n, int m, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i = 0 ; i < puddles.size() ; i++){
        map[puddles[i][0]][puddles[i][1]] = -1;
    }
    map[1][1] = 1;
    
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(map[i][j] == -1) continue;
            bool isTopPossible = false;
            bool isLeftPossible = false;
            
            if(j >= 2 && map[i][j - 1] != -1){
                isTopPossible = true;
            }
            if(i >= 2 && map[i - 1][j] != -1){
                isLeftPossible = true;
            }
            if(isTopPossible == true && isLeftPossible == true){
                map[i][j] = (map[i-1][j] + map[i][j-1]) % 1000000007;
            }else if(isTopPossible == true){
                map[i][j] = map[i][j-1];
            }else if(isLeftPossible == true){
                map[i][j] = map[i-1][j];
            }
        }
    }
    
    answer = map[n][m];
  
    return answer;
}
