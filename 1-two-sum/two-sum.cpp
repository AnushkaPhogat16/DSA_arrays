class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;

        // for(int i = 0; i<nums.size()-1; i++){
        //     int dif = target - nums[i];

        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[j] == dif){
        //             ans.push_back(i);
        //             ans.push_back(j);

        //             return ans;
        //         }
        //     }

        // }

        // return ans;

        unordered_map<int, int> num_map; 

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i}; 
            }
            num_map[nums[i]] = i; 
        }

        return {};
    }
};