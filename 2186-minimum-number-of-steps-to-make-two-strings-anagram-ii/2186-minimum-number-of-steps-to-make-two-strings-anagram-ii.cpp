class Solution {
public:
    int minSteps(string s, string t) {
    unordered_map<char, int> mp;
	for(int i=0;i<size(s);i++)
		mp[s[i]]++;
	for(int i=0;i<size(t);i++)
		mp[t[i]]--;
	int cnt=0;
	for(auto i:mp)
		cnt+=abs(i.second);
	return cnt;
    }
};