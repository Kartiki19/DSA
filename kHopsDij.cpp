#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

int minDist(const vector<vector<int>>& flights, int n, int src, int dst, int k){
    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto flight: flights){
        int u = flight[0];
        int v = flight[1];
        int w = flight[2];
        adj[u].push_back({v,w});
    }

    queue<pair<int, pair<int, int>>> q;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    q.push({0,{src, 0}});

    while(!q.empty()){
        int node = q.front().second.first;
        int wt = q.front().second.second;
        int stops = q.front().first;
        q.pop();

        if(stops > k) continue;

        for(auto edge: adj[node]){
            int v = edge.first;
            int w = edge.second;
            if(stops <= k && wt+w < dist[v]){
                dist[v] = wt+w;
                q.push({stops+1, {v, dist[v]}});
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main(){
    int n = 4;
    vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}};
    int src = 0, dst = 3, k = 1;

    int answer = minDist(flights, n, src, dst, k);

    cout << "Minimum distance with k hops is " << answer << endl; 
    return 0;
}