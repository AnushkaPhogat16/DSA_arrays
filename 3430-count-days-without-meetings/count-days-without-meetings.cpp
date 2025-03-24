class Solution {
public:
    int countDays(int days, vector<vector<int>>& M) {
        if (M.empty()) return days;

        sort(M.begin(), M.end());

        int res = M[0][0] - 1;

        int E = M[0][1];
        
        for(int i = 1; i < M.size(); i++){
            int currS = M[i][0];
            int currE = M[i][1]; 

            if(currS <= E + 1){
                E = max(E, currE);
                // if(currE > E){
                //     E = currE;
                // }
            } else {
                res += currS - E - 1 ;
                E = currE;
            }


        }

        return res + days - E;
    }
};