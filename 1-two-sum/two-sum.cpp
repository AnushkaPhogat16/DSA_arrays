class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapp;

        for(int i = 0; i< nums.size(); i++){
            int complimentary = target-nums[i];
            if(mapp.find(complimentary) != mapp.end()){
                return {i, mapp[complimentary]};
            }

            mapp[nums[i]] = i;
        }

        return {-1, -1};

    }
};