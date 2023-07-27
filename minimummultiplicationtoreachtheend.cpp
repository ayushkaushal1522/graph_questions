#include<bits/stdc++.h>
using namespace std;
// time complexity is given by O(100000*N) where n is the number of elements i the array.
int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> distance(100000,1e9);
        distance[start]=0;
        while(!q.empty()){
            auto it =  q.front();
            q.pop();
            int step=it.second;
            int val=it.first;
            
            for(auto it :arr){
                int num = (it*val)%100000;
                if(step+1<distance[num]){
                    distance[num]=step+1;
                    if(num==end) return step+1;
                    q.push({num,step+1});
                }
            }
            
        }
        return -1;
    }
int main(){






    return 0;
}