#include<bits/stdc++.h>
using namespace std;
//Assuming one based indexing
//Space complexity is given by O(n)
//time complexity is given by O(n)+O(2*e)
vector<int> bfs(int v , vector<int> adj[]){
    int visited[v+1]={0};
    visited[1]=1;
    queue<int> q;
    q.push(1);
    vector<int> ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it :adj[node]){
            if(visited[it]==0){
                visited[it]=1;
                q.push(it);
            }
        }
        ans.push_back(node);
    }
    return ans;


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

    vector<int> res=bfs(n,adj);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    






    return 0;
}
