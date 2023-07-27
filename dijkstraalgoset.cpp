#include<bits/stdc++.h>
using namespace std;
// time complexity is generally given by o(elogv)
//we usually use this algo in case of the undirected graph only.
int main(){





    return 0;
}
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
       set<pair<int,int>> st;
       vector<int> distance(V,1e9);
       st.insert({0,S});
       distance[S]=0;
       
       
       while(!st.empty()){
           auto it = *(st.begin());
           int node = it.second;
           int dis=it.first;
           st.erase(it);
           
           for(auto it :adj[node]){
               int temp=it[0];
               int ew=it[1];
               
               if(dis+ew<distance[temp]){
                   
                   if(distance[temp]!=1e9){
                       st.erase({distance[temp],temp});
                   }
                   
                   distance[temp]=dis+ew;
                   st.insert({distance[temp],temp});
               }
           }
       }
       return distance;
    }