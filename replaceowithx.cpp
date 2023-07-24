#include<bits/stdc++.h>
using namespace std;
// time complexity->O(n)+O(m)+O(n*m*4);
// space complexity-> O(n*m) 
void dfs(int i , int j, vector<vector<char>> mat , vector<vector<int>> &visited,int n,int m){
        visited[i][j]=1;
        int row[]={-1,0,1,0};
	    int col[]={0,1,0,-1};
	    for(int k=0;k<4;k++){
	        int nr=i+row[k];
	        int nc=j+col[k];
	        if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
	        if(visited[nr][nc]==0 && mat[nr][nc]=='O'){
	            dfs(nr,nc,mat,visited,n,m);
	        }
	    }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O'){
                dfs(0,i,mat,visited,n,m);
            }
            if(mat[n-1][i]=='O'){
                dfs(n-1,i,mat,visited,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                dfs(i,0,mat,visited,n,m);
            }
            if(mat[i][m-1]=='O'){
                dfs(i,m-1,mat,visited,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
        
        
    }
int main(){


    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m,'a'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<char>> res=fill(n,m,arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }







    return 0;
}