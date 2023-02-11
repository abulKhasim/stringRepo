// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// "bbbaaccdde"
// "bacdbacdbe"

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        string ans="";
        for(int i=0; i<s.size(); i++)
            mp[s[i]]++;

        priority_queue<pair<int,char> > maxHeap;
        for(auto it:mp){
            maxHeap.push(make_pair(it.second,it.first));
        }

        while(maxHeap.size()>1){
            auto top1=maxHeap.top();
            maxHeap.pop();
            auto top2=maxHeap.top();
            maxHeap.pop();

            ans+=top1.second;
            ans+=top2.second;

            top1.first-=1;
            top2.first-=1;
            if(top1.first>0)
            maxHeap.push(top1);
            if(top2.first>0)
            maxHeap.push(top2);

        }

        if(maxHeap.size()!=0){
            if(maxHeap.top().first>1)
            return "";
            else
            ans+=maxHeap.top().second;

        }

        return ans;
    }
};

