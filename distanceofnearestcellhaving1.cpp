#include<bits/stdc++.h>
using namespace std;
// time complexity ->O(n*m)+O(n*m*4)
// space complexity -> O(n*m) approx
vector<vector<int>> nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> visited(n,vector<int>(m,0));
	    vector<vector<int>> distance(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1) {q.push({{i,j},0}); visited[i][j]=1;}
	        }
	    }
	    while(!q.empty()){
	        pair<pair<int,int>,int> node=q.front();
	        q.pop();
	        int r=node.first.first;
	        int c=node.first.second;
	        int dis=node.second;
	        distance[r][c]=dis;
	        int row[]={-1,0,1,0};
	        int col[]={0,1,0,-1};
	        for(int k=0;k<4;k++){
	            int nr=r+row[k];
	            int nc=c+col[k];
	            if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
	            if(visited[nr][nc]==0){
	                q.push({{nr,nc},dis+1});
	                visited[nr][nc]=1;
	            }
	        }
	       
	    }
	    return distance;
	    
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
    vector<vector<int>> res=nearest(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }








    return 0;
}