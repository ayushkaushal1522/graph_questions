#include<bits/stdc++.h>
using namespace std;

bool dfs(int i,vector<int> adj[] , vector<int> &visited ,vector<int> &pathvisited){
        visited[i]=1;
        pathvisited[i]=1;
        for(auto it : adj[i]){
            if(visited[it]==0){
                if(dfs(it,adj,visited,pathvisited)==true){
                    return true;
                }
            }
            else if(pathvisited[it]==1){
                return true;
            }
        }
        pathvisited[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(dfs(i,adj,visited,pathvisited)==true) return true;
            }
        }
        return false;
    }
int main(){








    return 0;
}