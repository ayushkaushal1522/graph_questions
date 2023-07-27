#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it :edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distance(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        distance[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            auto it =pq.top();
            int dis=it.first;
            int node=it.second;
            pq.pop();
            
            for(auto it :adj[node]){
                int temp=it.first;
                int ew=it.second;
                if(dis+ew<distance[temp]){
                    distance[temp]=dis+ew;
                    pq.push({dis+ew,temp});
                    parent[temp]=node;
                }
            }
            
            
        }
        if(distance[n]==1e9) return {-1};
        vector<int> ans;
        int no=n;
        while(parent[no]!=no){
            ans.push_back(no);
            no=parent[no];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
int main(){







    return 0;
}