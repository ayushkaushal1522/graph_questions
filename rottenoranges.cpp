#include<bits/stdc++.h>
using namespace std;
// Time complexity is ->~~O(n*m)+O(n*m*4)
// Space cmplexity is ->O(n*m)
void bfs(vector<vector<int>> arr,vector<vector<int>> &visited,int n,int m,int &count){
               queue<pair<pair<int,int>,int>> q;
               for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(arr[i][j]==2) {q.push({{i,j},0});visited[i][j]=2;}
                    }
               }
               
               int row[]={-1,0,1,0};
               int col[]={0,1,0,-1};
               while(!q.empty()){
                pair<pair<int,int>,int> rotten=q.front();
                q.pop();
                int r=rotten.first.first;
                int c=rotten.first.second;
                int time=rotten.second;
                count=max(count,time);
                for(int k=0;k<4;k++){
                    int newrow=r+row[k];
                    int newcol=c+col[k];
                    if(newrow<0 || newrow>=n || newcol<0 || newcol>=m || arr[newrow][newcol]==0){
                        continue;
                    }
                    if(arr[newrow][newcol]==1 && visited[newrow][newcol]!=2){
                        visited[newrow][newcol]=2;
                        q.push({{newrow,newcol},time+1});
                    }
                }
               }
    } 
    int orangesRotting(vector<vector<int>>& arr) {
        // Code here
        int count=0;
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        bfs(arr,visited,n,m,count);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=2 && arr[i][j]==1) return -1;
            }
        }
        return count;
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
    int ans=orangesRotting(arr);
    return ans;

    








    return 0;
}