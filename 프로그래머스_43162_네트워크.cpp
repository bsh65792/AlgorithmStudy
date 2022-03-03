#include <string>
#include <vector>

using namespace std;

//dfs로 구현. 2차원 벡터를 만들어서 조사했는지 확인. 0이면 미연결, 1이면 연결.
//

int check[200]= {0, };
int cnt = 0;
vector<vector<int>> computersTemp;

void dfs(int i){

    printf("\n");
    check[i] = 1;
    
    for(int j = 0 ; j <computersTemp.size() ; j++){
        if(computersTemp.at(i).at(j) == 1){
            if(check[j] == 0){
                dfs(j);
            }
        }
    }
    
    
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    computersTemp = computers;
    
    for(int i = 0 ; i < computers.size(); i++){
        if(check[i] == 0){
            
            cnt++;
            dfs(i);
        }
    }

    answer = cnt;
    
    return answer;
}
