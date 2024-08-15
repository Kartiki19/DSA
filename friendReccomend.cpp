/*
Problem Statement: Friend Recommendation System
The application has n users, indexed from 1 to n, and m friendships represented as a 2D array friendships, where the i-th friendship is a connection between users friendship[i][0] and friendship[i][1].
A user x is suggested as a friend to user y if : 
    x and y are not already friends and 
    have the maximum number of common friends. 
    If there are multiple such users x, the one with the minimum index is suggested.
Given n and friendships, for each of the n users, find the index of the friend that should be recommended to them. If there is no recommendation available, report -1.
Example
Input: n = 5
friendships = [[1, 2], [2, 3], [1, 5]]
Output: [3, 4, 1, 1, 2]
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
void displayVector(const vector<int>& v){
    for(int i : v){
        cout << i << "\t";
    }
    cout << endl;
}

vector<int> solution(int& n, vector<vector<int>>& friendships){
    vector<int> output(n, -1);
    vector<unordered_set<int>> adj(n+1);
    for(auto friends: friendships){
        adj[friends[0]].insert(friends[1]);
        adj[friends[1]].insert(friends[0]);
    }

    for(int i = 1; i <= n; ++i){
        unordered_map<int, int> common_friends;
        int maxF = 0;
        for(int f1: adj[i]){
            for(int f2: adj[f1]){
                if(f2 != i && adj[i].find(f2) == adj[i].end()){
                    common_friends[f2]++;
                    if(common_friends[f2] > maxF){
                        maxF = common_friends[f2];
                        output[i-1] = f2;
                    }else if(common_friends[f2] == maxF && output[i-1] != -1 && f2 < output[i-1])
                        output[i-1] = f2;    
                }
            }
        }
    }
    return output;
}

int main(){
    int n = 5;
    vector<vector<int>> friendships = {{1,2}, {1,3}, {2,4}, {4,5}};
    vector<int> friends = solution(n, friendships);
    displayVector(friends);
    return 0;
}