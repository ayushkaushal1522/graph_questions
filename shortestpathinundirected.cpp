#include<bits/stdc++.h>
using namespace std;
 vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        vector<int> distance(N);
        for(int i=0;i<N;i++){
            distance[i]=1e9;
        }
        distance[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it :adj[temp]){
                if(distance[temp]+1<distance[it]){
                    distance[it]=distance[temp]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<N;i++){
            if(distance[i]==1e9){
                distance[i]=-1;
            }
        }
        return distance;
        
    }
int main(){








    return 0;
}