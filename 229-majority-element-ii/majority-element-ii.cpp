class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int candidate1 = -1;
        int candidate2 = -1;
        int count1 = 0;
        int count2 = 0;
        

        //has to be greater than freq

        for( int num : nums){
            if(num == candidate1){
                count1++;
            }else if(num == candidate2){
                count2++;
            }else if(count1 == 0){
                candidate1 = num;
                count1++;
            }else if(count2 == 0){
                candidate2 = num;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;

        for(int num : nums){
            if(num  == candidate1) count1++;
            else if(num == candidate2) count2++;
        }

        if(count1 > nums.size() / 3) ans.push_back(candidate1);
        if(count2 > nums.size() / 3) ans.push_back(candidate2); 

        return ans;
    }
};