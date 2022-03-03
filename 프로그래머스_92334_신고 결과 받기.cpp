#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>

using namespace std;

unordered_map<string, set<string>> sinGoUser;
unordered_map<string, int> sinGoOkayCount;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(int i = 0 ; i < report.size() ; i++){
        stringstream ss;
        ss.str(report[i]);
        string first, second;
        getline(ss, first, ' ');
        getline(ss, second, ' ');
        
        sinGoUser[second].insert(first);
    }
    
    for(int i = 0 ; i < id_list.size() ; i++){
        if(sinGoUser[id_list[i]].size() >= k){
            for(auto j = sinGoUser[id_list[i]].begin() ; j != sinGoUser[id_list[i]].end() ; j++){
                sinGoOkayCount[*j]++;
            }
        }
    }
    
    for(int i = 0 ; i < id_list.size() ; i++){
        answer.push_back(sinGoOkayCount[id_list[i]]);
    }
    
    
    return answer;
}



/*#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream> //stringstream 토큰 사용

using namespace std;

unordered_map<string, int> checkDoubleSinGo;
unordered_map<string, vector<string>> whoSinGo;
unordered_map<string, int> sinGoCount;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    
    for(int i = 0 ; i < report.size() ; i++){
        if(checkDoubleSinGo[report[i]] == 0){
            checkDoubleSinGo[report[i]]++;

            stringstream ss;
            ss.str(report[i]);
            string first, second;
            
            getline(ss, first, ' ');
            getline(ss, second, ' ');

            whoSinGo[first].push_back(second);
            sinGoCount[second]++;
        }
    }
    
    for(int i = 0 ; i < id_list.size() ; i++){
        int count = 0;
        int whoSinGoSize = whoSinGo[id_list[i]].size();
        for(int j = 0 ; j < whoSinGoSize ; j++){
            if(sinGoCount[whoSinGo[id_list[i]][j]] >= k) count++;
        }
        answer.push_back(count);
    }

    return answer;
}*/
