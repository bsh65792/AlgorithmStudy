#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;


//해시맵에 저장.
//for 문으로, phone_book에 저장된 string들 중에 공백은 없앤 다음, key값으로 저장 후 value++
bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> temp;
    string phoneBookTemp = "";
    string phoneNumberTemp;
    string token;
    
    
    for(int i = 0 ; i < phone_book.size() ; i++){
        phoneBookTemp = "";
        stringstream ss(phone_book.at(i));
        
        while(getline(ss, token, ' ')){
            phoneBookTemp = phoneBookTemp + token;
        }
        phone_book.at(i) = phoneBookTemp;
        temp[phone_book.at(i)]++;
        //printf("%s ", phoneBookTemp.c_str());
    }
    
    for(int i = 0 ; i < phone_book.size() ; i++){
        
        phoneNumberTemp = "";
        for(int j = 0 ; j < phone_book.at(i).length() - 1 ; j++){
            phoneNumberTemp = phoneNumberTemp + phone_book.at(i)[j];
            
            temp[phoneNumberTemp]--;
            if(temp[phoneNumberTemp] == 0){
                answer = false;
                return answer;
            }
        }
    }
    
    
    
    
    return answer;
}
