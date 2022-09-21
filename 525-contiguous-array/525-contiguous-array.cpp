class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0;
        int count0 = 0, count1 = 0;
        for(int i = 0;i < nums.size();i++) {
            int num = nums[i];
            count0 += num == 0;
            count1 += num == 1;
            int key = count0 - count1;
            if(mp.find(key) != mp.end()) {
                res = max(res, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }
        return res;
    }
};