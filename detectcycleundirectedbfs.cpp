#include<bits/stdc++.h>
using namespace std;
 bool bfs(int n , vector<int> adj[],vector<int> &visited){
            // vector<int> visited(n,0);
            visited[n]=1;
            queue<pair<int,int>> q;
            q.push({n,-1});
            while(!q.empty()){
                pair<int,int> pp=q.front();
                q.pop();
                int node=pp.first;
                int parent=pp.second;
                for(auto it :adj[node]){
                    if(visited[it]==0){
                        visited[it]=1;
                        q.push({it,node});
                    }
                    else if(parent!=it){
                        return true;
                    }
                }
            }
            return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool result=false;
        vector<int> visited(V,0);
        // visited[0]=1;
        for(int i=0;i<V;i++){
            if(visited[i]==0)
                result |= bfs(i,adj,visited);
            // return result;
        }
        return result;
    }
int main(){

    int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    bool result = isCycle(n,adj);
    cout<<result<<endl;




    return 0;
}