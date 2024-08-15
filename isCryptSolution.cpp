#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool solution(vector<string> crypt, vector<vector<char>> solution) {
    unordered_map<char, int> solution_map;
    for(auto it: solution){
        solution_map[it[0]] = it[1];
    }
    
    vector<long> w;
    for(int i = 0; i < crypt.size(); i++){
        if(crypt[i].size() > 1 && solution_map[crypt[i][0]] == '0') return false;
        string temp;
        for(char c: crypt[i]){
            temp += solution_map[c];
        }
        w.push_back(stol(temp));
    }
    
    return (w[2] == w[0] + w[1]);
    
}

int main(){
    vector<string> crypt = {"AAAAAAAAAAAAAA", "BBBBBBBBBBBBBB", "CCCCCCCCCCCCCC"};
    vector<vector<char>> dict = {{'A','1'}, {'B', '2'}, {'C', '3'}};
    cout << solution(crypt, dict);
    return 0;
}