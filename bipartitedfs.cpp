#include<bits/stdc++.h>
using namespace std;
//Assuming one based indexing.
// same as that of the simple bfs algorithm.
//Space complexity is given by O(n)
//time complexity is given by O(n)+O(2*e)
bool dfs(int i , vector<int>adj[] ,vector<int> &color, int V ,int c){
        color[i]=c;
        c = (c==0?1:0);
        for(auto it :adj[i]){
            if(color[it]==-1){
                if(dfs(it,adj,color,V,c)==false){
                    return false;
                }
            }
            else if(color[it]!=c){
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	   // int c=0;
	    for(int i=0;i<V;i++){
	        int c=0;
	        if(color[i]==-1){
	            if(dfs(i,adj,color,V,c)==false){
	                return false;
	            }
	        }
	        
	    }
	    return true;
	}

int main(){









    return 0;
}