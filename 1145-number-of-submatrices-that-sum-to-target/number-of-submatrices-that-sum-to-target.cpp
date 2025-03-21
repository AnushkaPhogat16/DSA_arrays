class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Step 1: Compute row-wise prefix sum
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int result = 0;

        // Step 2: Iterate over all column pairs
        for (int startCol = 0; startCol < cols; startCol++) {
            for (int j = startCol; j < cols; j++) {

                unordered_map<int, int> mp;  // HashMap to store cumulative sum frequencies
                mp[0] = 1;  // Base case: 0-sum occurs once

                int cumSum = 0;

                // Step 3: Iterate over rows and apply subarray sum logic
                for (int row = 0; row < rows; row++) {
                    // Compute submatrix sum from startCol to j for this row
                    cumSum += matrix[row][j] - (startCol > 0 ? matrix[row][startCol - 1] : 0);

                    // Check if (cumSum - target) exists in map (i.e., a valid submatrix is found)
                    if (mp.find(cumSum - target) != mp.end()) {
                        result += mp[cumSum - target];
                    }

                    // Store current cumulative sum frequency
                    mp[cumSum]++;
                }
            }
        }

        return result;
    }
};
