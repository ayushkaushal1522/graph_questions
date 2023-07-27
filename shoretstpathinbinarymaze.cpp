#include<bits/stdc++.h>
using namespace std;


int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> arr(n,vector<int>(m,1e9));
        arr[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        if(source.first==destination.first && source.second==destination.second){
            return 0;
        }
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            auto it =q.front();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            
            
            for(int k=0;k<4;k++){
                int nrow=r+row[k];
                int ncol=c+col[k];
                if(nrow<0 || ncol<0 || nrow>=n || ncol>=m) continue;
                if(dis+1<arr[nrow][ncol] && grid[nrow][ncol]==1){
                    arr[nrow][ncol]=dis+1;
                    if(nrow==destination.first && ncol==destination.second){
                        return dis+1;
                    }
                    q.push({dis+1,{nrow,ncol}});
                    
                }
            }
        }
        return -1;
        
    }
int main(){




    return 0;
}