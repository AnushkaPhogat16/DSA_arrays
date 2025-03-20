class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currS = 0, maxS = INT_MIN;

        for(int num : nums){
            currS += num;

            maxS = max(maxS, currS);
            if(currS < 0){
                currS = 0;
            }
        }

        return maxS;

    }
};