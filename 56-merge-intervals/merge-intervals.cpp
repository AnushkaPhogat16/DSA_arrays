class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {

        sort(I.begin(), I.end());

        vector<vector<int>> current;

        current.emplace_back(I[0]); 


        for(int i = 1; i < I.size(); i++){


            if(I[i][0] <= current.back()[1]){
                if(I[i][1] > current.back()[1]){
                    current.back()[1] = I[i][1];
                }
            }else{
                current.push_back(I[i]);
            }
        }  

        return current;  

    }
};