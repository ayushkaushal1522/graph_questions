#include<bits/stdc++.h>
using namespace std;
 bool dfs(int i,vector<int> adj[] , vector<int> &visited ,vector<int> &pathvisited,vector<int> &check){
        visited[i]=1;
        pathvisited[i]=1;
        check[i]=0;
        for(auto it : adj[i]){
            if(visited[it]==0){
                if(dfs(it,adj,visited,pathvisited,check)==true){
                    check[it]=0;
                    return true;
                }
            }
            else if(pathvisited[it]==1){
                check[it]=0;
                return true;
            }
        }
        check[i]=1;
        pathvisited[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
         vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        vector<int> check(V,0);
        vector<int> safe;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i,adj,visited,pathvisited,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                safe.push_back(i);
            }
        }
        return safe;
    }
int main(){










    return 0;
}