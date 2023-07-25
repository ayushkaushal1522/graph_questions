#include<bits/stdc++.h>
using namespace std;
// Space complexity -> O(n*m)
// Time complexity -> O(n*m*log(n*m))+O(n*m*4)
void dfs(int i,int j,vector<vector<int>> &grid , vector<vector<int>> &visited,vector<pair<int,int>> &temp,int ri,int ci,int n,int m){
        visited[i][j]=1;
        temp.push_back({i-ri,j-ci});
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=i+row[k];
            int nc=j+col[k];
            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(visited[nr][nc]==0 && grid[nr][nc]==1){
                dfs(nr,nc,grid,visited,temp,ri,ci,n,m);
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>> temp;
                    dfs(i,j,grid,visited,temp,i,j,n,m);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=countDistinctIslands(arr);
    cout<<ans<<endl;









    return 0;
}