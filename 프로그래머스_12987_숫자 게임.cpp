#include <string>
#include <vector>
#include <algorithm>

//A, B 둘다 소트
//for문으로 반복해가면서 B가 A보다 클 때 까지 반복해서 큰 수가 나오면 answer++
//물론 한번 검사한 벡터는 빼버린다.
//while로 B벡터가 다 없어지면 게임은 끝
//for문 다 돌아도 끝

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int a = 0;
    for(int i = 0 ; i < B.size() ; i++){
        if(A.at(a) < B.at(i)){
            a++;
            answer++;
            continue;
        }
    }
    
    /*
    for(int i = 0 ; i < A.size() ; i++){
        if(B.size() == 0){
            break;
        }else{
            while(A.at(i) >= B.at(0)){
                //작으면 버린다.
                B.erase(B.begin());
                if(B.size() == 0){
                    break;
                }
            }
            if(B.size() != 0){
                if(A.at(i) < B.at(0)){
                    answer++;
                    B.erase(B.begin());
                    if(B.size() == 0){
                        break;
                    }
                }
            }
            
        }
    }
    */
    
    
    
    
    return answer;
}
