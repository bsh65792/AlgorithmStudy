#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i = 0 ; i < scoville.size() ; i++){
        q.push(scoville[i]);
    }
    int first = 0;
    int second = 0;
    while(q.top() < K){
        if(q.size() <= 1){
            return -1;
        }
        first = q.top(); q.pop();
        second = q.top(); q.pop();
        q.push(first + second * 2);
        answer++;
    }
    
    
    return answer;
}
