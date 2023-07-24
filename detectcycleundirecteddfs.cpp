#include<bits/stdc++.h>
using namespace std;
 bool dfs(int n , vector<int> adj[],vector<int> &visited,int parent){
        visited[n]=1;
        for(auto it :adj[n]){
            if(visited[it]==0){
                if(dfs(it,adj,visited,n)==true){
                    return true;
                }
            }
            else if(it!=parent){
                return true;
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
            if(visited[i]==0){
                int parent = -1;
                result |= dfs(i,adj,visited,parent);
            }
          
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