#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

//양 쪽에 자신보다 작은게 둘 다 있으면 탈락!
//따라서 정답은 a - 양쪽부분 모두 자신보다 작은 풍선이 존재하는 풍선의 갯수
//양 옆 풍선은 무조건 끝까지 살아남는다.
//1. 맨 왼쪽에서부터 우선순위큐에 하나씩 넣었을 때, top이 본인이 아닌 애들을 따로 heap에 풍선의 번지수의 벨류에++
//2. 맨 오른쪽에서부터 또다른 우선순위큐에 하나씩 넣었을 때, top이 본인이 아닌 애들의 heap에 value-- 해서 0이면
//   양 쪽 다 자신보다 작은 수이다!!(answer++해줌)

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int shouldBomb = 0;
    unordered_map<int, int> hashMap;
    
    priority_queue<int, vector<int>, greater<int>> frontQueue;//왼쪽에서부터 검사할 때
    priority_queue<int, vector<int>, greater<int>> rearQueue;//오른쪽에서부터 검사할 때
    
    
    for(int i = 0 ; i < a.size() ; i++){
        frontQueue.push(a.at(i));
        
        //본인보다 더 작은 수가 왼쪽에 있는 경우
        if(frontQueue.top() != a.at(i)){
            hashMap[i]++;
        }
    }
    
    for(int i = a.size() - 1 ; i >= 0 ; i--){
        rearQueue.push(a.at(i));
        
        //본인보다 더 작은 수가 오른쪽에 있는 경우
        if(rearQueue.top() != a.at(i)){
            hashMap[i]--;
            
            //왼쪽도, 오른쪽도, 본인보다 작은 수가 있는 경우(무조건 터져야 하는 풍선이다)
            if(hashMap[i] == 0){
                shouldBomb++;
            }
        }
    }
    
    answer = a.size() - shouldBomb;
    
    
    return answer;
}
