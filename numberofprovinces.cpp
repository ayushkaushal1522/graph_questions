#include<bits/stdc++.h>
using namespace std;
//Assuming one based indexing
//Space complexity is given by O(n)+O(n)
//time complexity is given by O(n)+O(V+2*e)
void dfs(int v , vector<int> adj[],vector<int> &res,vector<int> &visited){
    res.push_back(v);
    visited[v]=1;
    for(auto it : adj[v]){
        if(visited[it]==0){
            dfs(it,adj,res,visited);
        }
    }


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
    vector<int> res;
    vector<int> visited(n+1,0);
    int count=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            count++;
            dfs(i,adj,res,visited);
        }
    }
    cout<<count<<endl;
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";

    






    return 0;
}
