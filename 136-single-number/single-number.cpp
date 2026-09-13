class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for (int num : nums) {
            r ^= num;
        }
        return r;
    }
};