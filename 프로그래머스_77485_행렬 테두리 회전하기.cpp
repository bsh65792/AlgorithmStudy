#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int map[101][101] = {0, };
int rows;
int columns;
vector<int> answer;
vector<vector<int>> queries;

void SetMap();
void RotateMap(int startY, int startX, int endY, int endX);

vector<int> solution(int rowsTemp, int columnsTemp, vector<vector<int>> queriesTemp) {
    rows = rowsTemp;
    columns = columnsTemp;
    queries = queriesTemp;
    
    SetMap();
    
    for(int i = 0 ; i < queriesTemp.size() ; i++){
        RotateMap(queriesTemp[i][0], queriesTemp[i][1], queriesTemp[i][2], queriesTemp[i][3]);
    }
    
    return answer;
}


void SetMap(){
    for(int i = 1 ; i <= rows ; i++){
        for(int j = 1 ; j <= columns ; j++){
            map[i][j] = (i - 1) * columns + j;
        }
    }
}

void RotateMap(int startY, int startX, int endY, int endX){
    
    priority_queue<int, vector<int>, greater<int>> q;
    
    int temp1 = map[startY][endX];
    for(int x = endX - 1 ; x >= startX ; x--){
        map[startY][x + 1] = map[startY][x];
        q.push(map[startY][x + 1]);
    }
    
    int temp2 = map[endY][endX];
    for(int y = endY - 1 ; y > startY ; y--){
        map[y + 1][endX] = map[y][endX];
        q.push(map[y + 1][endX]);
    }
    map[startY + 1][endX] = temp1;
    q.push(map[startY + 1][endX]);
    
    int temp3 = map[endY][startX];
    for(int x = startX + 1 ; x < endX ; x++){
        map[endY][x - 1] = map[endY][x];
        q.push(map[endY][x - 1]);
    }
    map[endY][endX - 1] = temp2;
    q.push(map[endY][endX - 1]);
    
    int temp4 = map[startY][startX];
    for(int y = startY + 1 ; y < endY ; y++){
        map[y - 1][startX] = map[y][startX];
        q.push(map[y - 1][startX]);
    }
    map[endY - 1][startX] = temp3;
    q.push(map[endY - 1][startX]);
    
    map[startY][startX + 1] = temp4;
    q.push(map[startY][startX + 1]);
    
    answer.push_back(q.top());
    
    
}
