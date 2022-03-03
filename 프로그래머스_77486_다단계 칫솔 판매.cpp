#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parentName;
unordered_map<string, int> totalMoney;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0 ; i < enroll.size() ; i++){
        parentName[enroll[i]] = referral[i];//가담시킨 사람의 이름을 넣는다.
    }
    
    for(int i = 0 ; i < seller.size(); i++){
        int money = amount[i] * 100;
        string sellerTemp = seller[i];
        string parentTemp = parentName[sellerTemp];
        int cnt = 0;
        while(true){
            cnt++;
            if(cnt >= 1000) break;
            totalMoney[sellerTemp] = totalMoney[sellerTemp] + money - (money / 10);
            if(parentTemp == "-"){
                break;
            }
            money = money / 10;
            sellerTemp = parentTemp;
            parentTemp = parentName[parentTemp];
        }
    }
    
    for(int i = 0 ; i < enroll.size() ; i++){
        answer.push_back(totalMoney[enroll[i]]);
    }
    
    return answer;
}
