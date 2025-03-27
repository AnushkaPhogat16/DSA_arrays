class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int curr = 0;
        int majority;
        for(int i = 0; i < nums.size(); i++){
            if(curr == 0) majority = nums[i];
            
            if(nums[i] == majority) curr++;
            else{
                curr--;
            }
        }

        int totalFreq = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == majority){
                totalFreq++;
            }
        }

        int freq1 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == majority) freq1++;

            if( (2 * freq1 > i + 1) && (2 * (totalFreq - freq1) > nums.size() - 1 - i) ){
                return i;
            }
        }

        return -1;
    }
};