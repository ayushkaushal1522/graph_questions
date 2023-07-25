#include<bits/stdc++.h>
using namespace std;
//Assuming one based indexing.
// same as that of the simple bfs algorithm.
//Space complexity is given by O(n)
//time complexity is given by O(n)+O(2*e)
bool bfs(int i , vector<int>adj[] ,vector<int> &color, int n  ){
        queue<int> q;
        q.push(i);
        int c=0;
        color[i]=c;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            c=color[node];
            c=(c==0?1:0);
            for(auto it :adj[node]){
                if(color[it]==-1){
                    color[it]=c;
                    q.push(it);
                    
                }
                else if(color[it]!=c){
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    bool result = true ;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            result &= bfs(i,adj,color,V);
	        }
	        
	    }
	    return result;
	}
int main(){









    return 0;
}