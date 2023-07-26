#include<bits/stdc++.h>
using namespace std;
//jab  bhi something before something ka case ho na we should think about applying the topological sort algorithm.
void dfs(int i ,vector<int> adj[],vector<int> &visited ,stack<int> &st){
	    visited[i]=1;
	    for(auto it :adj[i]){
	        if(visited[it]==0){
	            dfs(it,adj,visited,st);
	        }
	    }
	    st.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(visited[i]==0){
	            dfs(i,adj,visited,st);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        int temp= st.top();
	        st.pop();
	        ans.push_back(temp);
	    }
	    return ans;
	}
int main(){











    return 0;
}