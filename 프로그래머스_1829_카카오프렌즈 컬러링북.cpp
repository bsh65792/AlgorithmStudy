#include <vector>
#include <queue>

using namespace std;

bool isMaxSizeOfOneArea(int size);
void BFS(int y, int x);



int numberOfArea;
int maxSizeOfOneArea;
int check[100][100];
int dy[4];
int dx[4];
int pictureSizeY;
int pictureSizeX;
vector<vector<int>> picture;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> pictureTemp) {
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            check[i][j] = 0;
        }
    }
    dy[0] = -1; dy[1] = 1; dy[2] = 0; dy[3] = 0;
    dx[0] = 0; dx[1] = 0; dx[2] = -1; dx[3] = 1;

    numberOfArea = 0;
    maxSizeOfOneArea = 0;
    vector<int> answer(2);
    picture = pictureTemp;
    pictureSizeY = picture.size();
    pictureSizeX = picture[0].size();
    
    for(int i = 0 ; i < pictureSizeY ; i++){
        for(int j = 0 ; j < pictureSizeX ; j++){
            if(check[i][j] == 0){
                if(picture[i][j] == 0){
                    check[i][j] = 1;
                    continue;
                }
                BFS(i, j);
            }
        }
    }
    
    
    answer[0] = numberOfArea;
    answer[1] = maxSizeOfOneArea;
    return answer;
}

void BFS(int y, int x){
    numberOfArea++;
    check[y][x] = 1;
    int areaSize = 1;
    int areaColor = picture[y][x];
    
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while(q.size() != 0){
        pair<int, int> loc = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newY = loc.first + dy[i];
            int newX = loc.second + dx[i];
            
            if(newY < 0 || newY >= pictureSizeY || newX < 0 || newX >= pictureSizeX)
                continue;
            if(check[newY][newX] != 0) continue;
            
            if(picture[newY][newX] == areaColor){
                areaSize++;
                check[newY][newX] = 1;
                q.push({newY, newX});
            }
        }
    }
    
    if(areaSize > maxSizeOfOneArea){
        maxSizeOfOneArea = areaSize;
    }
    
}
