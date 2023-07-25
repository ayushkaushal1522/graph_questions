#include<bits/stdc++.h>
using namespace std;
// just convert trhe given dictionary into the DAG then the problem reduces to just finding out the toposort of the answer.
 vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it :adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);
	        
	        for(auto it :adj[temp]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	    
	}
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.length(),s2.length());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> ans =topoSort(K,adj);
        string res="";
        for(auto it :ans){
            res=res+char(it+'a');
        }
        return res;
    }

int main(){









    return 0;
}