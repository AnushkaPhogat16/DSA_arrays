class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int curr = 0, majority = -1;

        // Step 1: Find the majority element using Boyer-Moore Voting Algorithm
        for (int num : nums) {
            if (curr == 0) majority = num;
            curr += (num == majority) ? 1 : -1;
        }

        // Step 2: Count occurrences of the majority element
        int totalFreq = count(nums.begin(), nums.end(), majority);
        int freq1 = 0;

        // Step 3: Find the valid split index
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == majority) freq1++;

            if (2 * freq1 > i + 1 && 2 * (totalFreq - freq1) > nums.size() - 1 - i) {
                return i;
            }
        }

        return -1;
    }
};
