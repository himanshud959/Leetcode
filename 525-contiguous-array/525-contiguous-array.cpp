class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0;
        int curr = 0;
        for(int i = 0;i < nums.size();i++) {
            int num = nums[i];
            if(num == 0) {
                num = -1;
            }
            curr += num;
            if(mp.find(curr) != mp.end()) {
                res = max(res, i - mp[curr]);
            } else {
                mp[curr] = i;
            }
        }
        return res;
    }
};