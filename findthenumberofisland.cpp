#include<bits/stdc++.h>
using namespace std;
time complexity ->O(n^2)+O(n^2*9)~~O(n^2)
space complexity ->O(n^2)
void bfs(int i,int j,vector<vector<int>> &arr ,vector<vector<int>> &visited){
    int n=arr.size();
    int m=arr[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=1;
    while(!q.empty()){
        pair<int,int> pp=q.front();
        q.pop();
        int row[]={-1,0,1,0,-1,-1,1,1};
        int col[]={0,1,0,-1,-1,1,1,-1};
        for(int k=0;k<8;k++){
            int newrow=pp.first+row[k];
            int newcol=pp.second+col[k];
            if(newrow<0 || newcol<0 || newrow>=n || newcol>=m || arr[newrow][newcol]==0){
                continue;
            }
            if(visited[newrow][newcol]==0){
                q.push({newrow,newcol});
                visited[newrow][newcol]=1;
            }
        }
    }
    
    
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
    vector<vector<int>> visited(n,vector<int>(m,0));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                if(visited[i][j]==0){
                    count++;
                    bfs(i,j,arr,visited);
                }
            }
        }
    }
    cout<<count<<endl;








    return 0;
}