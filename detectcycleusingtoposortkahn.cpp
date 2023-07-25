#include<bits/stdc++.h>
using namespace std;
// toposort is valid only for the DAG(directed acylic graph)
// there is a need to make the indegree array in case of the kahn algo.
// time complexity is given by O(n+e) as it is the directed graph and theis is simple a bfs.
bool topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it :adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);
	        
	        for(auto it :adj[temp]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	   if(ans.size()==V) return false;
       return true;
	    
	}
int main(){








    return 0;
}