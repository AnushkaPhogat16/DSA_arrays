class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit = 0;
        int minPrice = INT_MAX;

        for( int i = 0 ; i<nums.size(); i++){
            minPrice = min(minPrice, nums[i]);
            profit = max(profit, nums[i] - minPrice);

            

        }


        return profit;
    }
};