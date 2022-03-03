#include <string>
#include <vector>

using namespace std;

//1. yellow가 중심이 되어야 할 듯.
//2. for문으로, yellow의 세로를 1부터 yellow 수의 절반까지 올려보면서, yellow수랑 나누어 떨어지는지 확인.
//3. 나누어 떨어진다면, 그 때의 yellow의 가로의 길이*2 + 세로의 길이*2 + 4를 한 값이 갈색이 맞는지 확인.
//4. 아니라면 계속하고, 맞다면 break 후 가로, 세로 길이 넣기(혹시 모르니 한번 더 비교하고 넣기)

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = 0;
    int height = 0;
    
    for(int i = 1 ; i <= yellow ; i++){
        if(yellow % i == 0){
            if(i*2 + (yellow/i)*2 + 4 == brown){
                width = yellow/i + 2;
                height = i + 2;
                break;
            }
        }
    }
    
    if(width > height){
        answer.push_back(width);
        answer.push_back(height);
    } else{
        answer.push_back(height);
        answer.push_back(width);
    }
    
    
    return answer;
}
