#include<bits/stdc++.h>
using namespace std;
// time complexity is O(n*word length * 26 *log(n))
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;;
            int temp=q.front().second;
            q.pop();
            if(word==targetWord) return temp;
            for(int i=0;i<word.size();i++){
                char ori=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,temp+1});
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
int main(){









    return 0;
}