class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        long long n=size(skill);
        sort(skill.begin(), skill.end());
        long _=0,__=n-1;
        vector<int>temp;
        while(_<__)
        {
            temp.push_back(skill[_]+skill[__]);
            ans+=skill[_]*skill[__];
            _++,__--;
        }
        for(auto _=1;_<size(temp);_++)
        {
            if(temp[_-1]!=temp[_])
                return -1;
        }
        return ans;
    }
};