#include<bits/stdc++.h>
using namespace std;
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[V];
	    for(auto it :prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
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
	   if(ans.size()==V) return true;
       return false;
	}
int main(){









    return 0;
}