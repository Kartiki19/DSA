/*
Given a string str and array of pairs that indicates which indices in the string can be swapped, 
return the lexicographically largest string that results from doing the allowed swaps. 
You can swap indices any number of times.
*/

#include<iostream>
using namespace std;
#include<vector>

void dfs(int& node, vector<bool>& visited, const vector<vector<int>>& adj, vector<int>& component){
    visited[node] = true;
    component.push_back(node);
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, visited, adj, component);
        } 
    }
}

string solution(string& str, const vector<vector<int>>& pairs){
    int n = str.size();
    string output = "";

    vector<vector<int>> adj(n); /// 0-based index
    for(auto it: pairs){
        int u = it[0] - 1;
        int v = it[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n,false); /// 0-based index
    vector<vector<int>> components; /// 0-based index
    
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            vector<int> component;
            dfs(i, visited, adj, component); /// 0-based index
            components.push_back(component);
            string temp_str = "";
            for(int component: components[i]){
                temp_str += str[component];
            }

            sort(temp_str.begin(), temp_str.end(), greater<char>());
            sort(components[i].begin(), components[i].end());

            for(int  j = 0; j < components[i].size(); ++j){
                str[components[i][j]] = temp_str[j];
            }
        }
    }
    return str;
}

int main(){
    string str = "abdc";
    vector<vector<int>> pairs = {{1,4},{3,4}};
    cout << solution(str, pairs);
    return 0;
}