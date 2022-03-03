#include<vector>
#include<queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int dist[100][100] = {0, };
vector<vector<int>> maps;
int m;
int n;

void BFS();

int solution(vector<vector<int>> mapsTemp)
{
    maps = mapsTemp;
    m = mapsTemp.size();  //세로
    n = mapsTemp[0].size();  //가로
    
    BFS();
    
    int answer = dist[m - 1][n - 1] + 1;
    if(dist[m - 1][n - 1] == 0) return -1;
    return answer;
}

void BFS(){
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    maps[0][0] = 0;//이미 지나온 길은 벽으로 생각해주기
    
    while(q.size() != 0){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if(nextY < 0 || nextY >= m || nextX < 0 || nextX >= n){
                continue; //갈 수 없음
            }
            
            if(maps[nextY][nextX] == 0) continue;
            
            dist[nextY][nextX] = dist[nowY][nowX] + 1;
            maps[nextY][nextX] = 0; //못가게 막기
            q.push({nextY, nextX});
            
            
        }
    }
    
    
}
