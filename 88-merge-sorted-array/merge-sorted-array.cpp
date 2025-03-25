class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind = m + n - 1;  // Last position in nums1
        int ind1 = m - 1;  // Last valid element in nums1
        int ind2 = n - 1;  // Last element in nums2

        while (ind2 >= 0) {
            if (ind1 >= 0 && nums1[ind1] > nums2[ind2]) {
                nums1[ind--] = nums1[ind1--];
            } else {
                nums1[ind--] = nums2[ind2--];
            }
        }
    }
};
