#include<bits/stdc++.h>
using namespace std;
// Time complexity is -> O(X)+O(X*4)~~O(X)~~O(n*m)
// Space cmplexity is ->O(n*m)+O(n*m)
void dfs(int i, int j ,int incolor , int newcolor,vector<vector<int>> arr,vector<vector<int>> &visited,int n,int m){
    visited[i][j]=newcolor;
    int row[]={-1,0,1,0};
    int col[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int newrow=i+row[k];
        int newcol=j+col[k];
        if(newrow<0 || newcol<0 || newrow>=n || newcol>=m){
                continue;
        }
        if(arr[newrow][newcol]==incolor && visited[newrow][newcol]!=newcolor){
            dfs(newrow,newcol,incolor,newcolor,arr,visited,n,m);
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
    vector<vector<int>> visited = arr;
    int sr,sc,newcolor;
    cin>>sr>>sc>>newcolor;
    
    int incolor=arr[sr][sc];
    dfs(sr,sc,incolor,newcolor,arr,visited,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }








    return 0;
}