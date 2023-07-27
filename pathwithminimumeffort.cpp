#include<bits/stdc++.h>
using namespace std;

// time complexity is given by Elogv
// n*m*4*log(n*m)

int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> arr(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        arr[0][0]=0;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==n-1 && c==m-1) return dis;
            
            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];
                if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                int neff=max(abs(heights[r][c]-heights[nr][nc]),dis);
                if(neff<arr[nr][nc]){
                    arr[nr][nc]=neff;
                    pq.push({neff,{nr,nc}});
                }
            }
        }
        return 0;
        
    }

    int main(){





        return 0;
    }