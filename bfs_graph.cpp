#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> bfsGraph(int V, unordered_map<int, vector<int>>& adj){
    queue<int> q;
    vector<int> vis(V+1, 0);
    q.push(1);
    vis[1] = 1;
    vector<int> bfs_output;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        bfs_output.push_back(curr);

        for(int i: adj[curr]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }

    return bfs_output;

}
void display(vector<int> &v){
    for(int i : v){
        cout << i << "\t";
    }
}
int main(){
    unordered_map<int, vector<int>> adj = {
        {1, {2,6}},
        {2, {1, 3, 4}},
        {3, {2}},
        {4, {2, 5}},
        {5, {4, 7}},
        {6, {1 , 7, 8}},
        {7, {6, 5}},
        {8, {6}}
    };

    vector<int> bfs = bfsGraph(8, adj);
    display(bfs);
    return 0;
}

