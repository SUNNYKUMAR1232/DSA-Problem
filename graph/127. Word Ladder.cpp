#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string firstchange(string word, unordered_set<string> &st, int i,
                       int &count)
    {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if (st.find(word) != st.end())
            {
                st.erase(word);
                count++;
                return word;
            }
        }
        return word;
    }
    void recursive(string s, string e, unordered_set<string> &st ,int &count,vector<int>&ans)
    {  
        int a=1;
        if (s == e){
            ans.push_back(count);
            return ;
        }
         
        for (int i = 0; i < s.size(); i++)
        {
            string word=firstchange(s, st, i, count);
            if(word!=s)
            {
                recursive(word, e, st,count,ans);}
        }
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {
         int count=0;
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<int>ans;
        recursive(beginWord, endWord, st,count,ans);
        for(auto it:ans) return count;
       return 0;
    }
};

int main()
{
    int n;
    cin >> n;
    string s, e;
    cin >> s >> e;
    vector<string> wordList;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        wordList.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        cout << wordList[i] << " ";
        cout << endl;
    }
    Solution obj;
    cout<<obj.ladderLength(s,e,wordList);
}