class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        long long mx=INT_MIN;
        long long cnt=0;
        for(auto _=0;_<size(nums);_++)
        {
            if(nums[_]==1)
            {
                cnt++;
            }
            else
            {
                cnt=0;
            }
            mx=max(mx,cnt);
        }
        return mx;
    }
};