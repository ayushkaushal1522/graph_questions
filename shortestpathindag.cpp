#include<bits/stdc++.h>
using namespace std;
// time complexity -> O(n+m)+time complexity of topoSort
void dfs(int i ,vector<pair<int,int>> adj[],vector<int> &visited ,stack<int> &st){
	    visited[i]=1;
	    for(auto it :adj[i]){
	        if(visited[it.first]==0){
	            dfs(it.first,adj,visited,st);
	        }
	    }
	    st.push(i);
	}
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            
        }
        vector<int> visited(N,0);
        stack<int> st;
        for(int i=0;i<N;i++){
            if(visited[i]==0){
                dfs(i,adj,visited,st);
            }
        }
        vector<int> dist(N);
        for(int i=0;i<N;i++) dist[i]=1e9;
        dist[0]=0;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            
            for(auto it :adj[temp]){
                int v=it.first;
                int wt=it.second;
                if(dist[temp]+wt<dist[v]){
                    dist[v]=dist[temp]+wt;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
        
    }
int main(){
    
    
    
    
    
    
    
    
    
    
    return 0;
}