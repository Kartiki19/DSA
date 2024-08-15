#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class solution{
    public:
        vector<int> dijkstra(int &n, vector<vector<int>> adj[]){
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            dist[0] = 0;
            pq.push({0, 0});

            while(!pq.empty()){
                int node = pq.top().second;
                int wt = pq.top().first;
                pq.pop();

                for(auto it: adj[node]){
                    int v = it[0];
                    int w = it[1];

                    if(wt + w < dist[v]){
                        dist[v] = wt + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        }
        void display(vector<int> &v){
            for(int i : v){
                cout << i << "\t";
            }
        }
};

int main(){
    int V = 6;
    vector<vector<int>> adj[] = {{{2,4}, {1, 4}}, 
                                    {{0, 4}, {2,2}}, 
                                    {{3,3}, {4,1},{5,6},{0,4},{1,2}}, 
                                    {{2, 3}, {5, 2}}, 
                                    {{2,1}, {5,3}}, 
                                    {{3,2}, {2,6}, {4,3}}};
    solution s;
    vector<int> dist = s.dijkstra(V, adj);
    s.display(dist);
}