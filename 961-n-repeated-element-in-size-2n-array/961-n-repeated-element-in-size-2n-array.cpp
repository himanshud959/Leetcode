class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int>pm;
        for(int i=0;i<size(nums);i++)
        {
            pm[nums[i]]++;
        }
        for(auto i:pm)
        {
            if(i.second==size(nums)/2)
                return i.first;
        }
        return {};
    }
};