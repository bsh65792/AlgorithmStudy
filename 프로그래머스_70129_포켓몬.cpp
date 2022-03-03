#include <string>
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;

string FirstProcess(string s);
string SecondProcess(string s);

int zeroCount = 0;

vector<int> solution(string s) {
    vector<int> answer;
    int calculationCount = 0;
    
    while(s.length() != 1){
        s = FirstProcess(s);
        if(s.length() != 1)
            s = SecondProcess(s);
        calculationCount++;
    }
    answer.push_back(calculationCount);
    answer.push_back(zeroCount);
    
    return answer;
}

string FirstProcess(string s){
    string returnString = "";
    
    stringstream ss;
    ss.str(s);
    
    int thisZeroCount = 0;
    
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '0') thisZeroCount++;
    }
    
    for(int i = 0 ; i <= thisZeroCount ; i++){
        string sTemp;
        
        getline(ss, sTemp, '0');
        returnString.append(sTemp);
    }
    
    zeroCount += thisZeroCount;
    
    return returnString;
    
}

string SecondProcess(string s){
    string returnString = "";
    
    int number = s.length();
    
    string binaryReverse = "";
    
    while(number != 1){
        if(number % 2 == 0){
            binaryReverse.append("0");
        }else{
            binaryReverse.append("1");
        }
        number /= 2;
    }
    binaryReverse.append("1");
    
    
    for(int i = binaryReverse.length() - 1 ; i >= 0 ; i--){
        if(binaryReverse[i] == '1')
            returnString.append("1");
        else
            returnString.append("0");
    }
    
    return returnString;
}
