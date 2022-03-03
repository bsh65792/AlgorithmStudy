#include <string>
#include <vector>
#include <queue>

using namespace std;

//bfs로 구현.
//queue에 노드의 시작점 데이터를 삽입.
//queue가 빌 때 까지 다음 노드의 위치를 넣고
//다음 노드의 distance에 노드의 거리를 삽입한다.(이전 노드의 distance보다 1 큰 수를 삽입.)
//일부러 1번 노드의 distance에는 1을 삽입하고, distance가 0인 곳만 안 다녀간 곳으로 체크한다.

int distances[20001] = {0, };//각 노드의 거리 집어넣는 용 + 다녀왔는지 체크용

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    queue<int> q;
    
    distances[1] = 1;
    q.push(1);
    
    int node = 0;
    
    while(q.size() != 0){
        node = q.front();
        q.pop();
        
        for(int i = 0 ; i < edge.size() ; i++){
            
            if(edge.at(i).at(0) == node){
                if(distances[edge.at(i).at(1)] == 0){
                    distances[edge.at(i).at(1)] = distances[node] + 1;
                    q.push(edge.at(i).at(1));
                    //이미 체크한 벡터의 값을  하나 빼 준다.
                    edge.erase(edge.begin() + i);
                    i--;
                }
            } else if(edge.at(i).at(1) == node){
                if(distances[edge.at(i).at(0)] == 0){
                    distances[edge.at(i).at(0)] = distances[node] + 1;
                    q.push(edge.at(i).at(0));
                    //이미 체크한 벡터의 값을  하나 빼 준다.
                    edge.erase(edge.begin() + i);
                    i--;
                }
            }//노드가 간 적 없는지 검사 if 끝
        }//노드검사를 위한 반복문 for 끝
    }//while 끝
    
    int largestNumber = -1;
    
    for(int i = 0 ; i < 20001 ; i++){
        if(distances[i] > largestNumber){
            largestNumber = distances[i];
        }
    }
    
    for(int i = 0 ; i < 20001 ; i++){
        if(distances[i] == largestNumber){
            answer++;
        }
    }
    
    
    
    return answer;
}
