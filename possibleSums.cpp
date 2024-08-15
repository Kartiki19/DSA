#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;

int solution(vector<int> coins, vector<int> quantity) {
    unordered_set<int> ps;
    ps.insert(0);
    
    for(int i = 0; i < coins.size(); ++i){
         unordered_set<int> temp = ps;
         for(int f = 1; f <= quantity[i]; ++f){
              for(auto it: temp){
                   ps.insert(it + coins[i]*f);
              }
         }
    }
    return ps.size()-1;
}

int main(){
     vector<int> coins = {10, 50, 100};
     vector<int> quantity = {1, 2, 1};
     cout << solution(coins, quantity);
     return 0;
}