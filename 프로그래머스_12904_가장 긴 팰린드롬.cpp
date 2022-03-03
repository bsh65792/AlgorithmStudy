#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 1;
    
    for(int i = 0 ; i < s.length() ; i++){
        int iter = 1;
        int length;
        while(true){
            if(i - iter < 0 || i + iter >= s.length()){
                length = (iter - 1) * 2 + 1;
                break;
            }
            if(s[i - iter] == s[i + iter]){
                iter++;
            }else{
                length = (iter - 1) * 2 + 1;
                break;
            }
        }
        if(length > answer) answer = length;
    }
    
    for(int i = 0 ; i < s.length() - 1 ; i++){
        if(s[i] == s[i + 1]){
            int iter = 1;
            int length;
            while(true){
                if(i - iter < 0 || i + 1 + iter >= s.length()){
                length = (iter - 1) * 2 + 2;
                break;
            }
            if(s[i - iter] == s[i + 1 + iter]){
                iter++;
            }else{
                length = (iter - 1) * 2 + 2;
                break;
            }
        }
        if(length > answer) answer = length;
        }else{
            continue;
        }
    }

    return answer;
}
