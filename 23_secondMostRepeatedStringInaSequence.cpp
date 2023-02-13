class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> map;
        for(int i=0; i<n; i++) map[arr[i]]++;
        
        priority_queue<pair<int, string>, vector<pair<int , string>>, greater<>> minh;
        
        for(auto i : map){
            minh.push({i.second, i.first});
            if(minh.size() > 2) minh.pop();
        }
        
        if(minh.size() > 1) return minh.top().second;
        else return "";
    }
};