#include<bits/stdc++.h>
using namespace std;
//This algo will not work in case of the negative weight edge length.
// because it will fall in an infinite loop.
// time complexity is given by O(Elogv).
// This algo will also work if we use queue in case of priority queue.
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distance(V);
        for(int i=0;i<V;i++) distance[i]=1e9;
        distance[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            pair<int,int> pp=pq.top();
            pq.pop();
            int dis=pp.first;
            int node=pp.second;
            for(auto it :adj[node]){
                int ew=it[1];
                int adnode=it[0];
                if(ew+dis<distance[adnode]){
                    distance[adnode]=ew+dis;
                    pq.push({ew+dis,adnode});
                }
            }
            
        }
        return distance;
        
    }
int main(){









    return 0;
}