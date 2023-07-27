#include<bits/stdc++.h>
using namespace std;
//distnace ko priority sene se baat nahi bante you know why 
// that's why priority has been given to the number of steps taken.
int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto it :flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> distance(n,1e9);
        distance[src]=0;
        while(!q.empty()){
            auto it =q .front();
            q.pop();
            int stop=it.first;
            int temp=it.second.first;
            int cost=it.second.second;
            if(stop>k) continue;
            for(auto it :adj[temp]){
                int anode=it.first;
                int ew=it.second;
                
                if(cost+ew<distance[anode] && stop<=k){
                    distance[anode]=cost+ew;
                    q.push({stop+1,{anode,cost+ew}});
                }
            }
            
            
            
        }
        if(distance[dst]==1e9) return -1;
        return distance[dst];
    }


int main(){



    return 0;
}


