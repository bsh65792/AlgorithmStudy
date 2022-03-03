#include <string>
#include <vector>

using namespace std;
//밖에 넘버 저장 벡터 필요
//밖에 타겟 저장 필요
//넘버 사이즈많큼 int형 벡터 필요(1이면 +, -1이면 -)
//재귀함수 인수에 1, -1로 플마 구분 필요, depth필요, 이때까지 계산한 수 필요

vector<int> numbersTemp;
int targetTemp;
int cnt;

void dfs(int depth, int result){
    
    if(depth == numbersTemp.size()){
        
        if(result == targetTemp){
            
            cnt++;
            //printf("%d ", cnt);
        }
        return;
    }
    
    dfs(depth + 1, result + numbersTemp.at(depth));
    dfs(depth + 1, result - numbersTemp.at(depth));
    
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    cnt = 0;
    numbersTemp = numbers;
    targetTemp = target;
    
    dfs(0, 0);
    
    
    answer = cnt;

    return answer;
}
