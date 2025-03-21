class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxProd = nums[0], minProd = nums[0], result = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if(nums[i] < 0){
                swap(minProd, maxProd);
            }

            minProd = min(nums[i], minProd*nums[i]);
            maxProd = max(nums[i], maxProd*nums[i]);

            result = max(result, maxProd);

        }

        return result;
    }
};
