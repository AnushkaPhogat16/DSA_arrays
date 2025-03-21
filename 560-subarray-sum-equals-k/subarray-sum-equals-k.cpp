class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> existence;
        existence[0]++;
        int cumSum = 0;

        int ans= 0;

        for(int i = 0; i < nums.size(); i++){
            cumSum += nums[i];
            if(existence.find(cumSum - k) != existence.end()){
                ans += existence[cumSum - k];
            }

            existence[cumSum]++;
        }

        return ans;
    }
};