class Solution {
public:
    int countDays(int days, vector<vector<int>>& M) {
        sort(M.begin(), M.end());

        int res = 0;

        int S = M[0][0];
        int E = M[0][1];

        if(S > 1){
            res += S - 1;
        }
        

        for(int i = 1; i < M.size(); i++){
            int currS = M[i][0];
            int currE = M[i][1]; 

            if(currS <= E + 1){
                if(currE > E){
                    E = currE;
                }
            }else if(currS > E + 1){
                res += currS - E - 1 ;
                S = currS;
                E = currE;
            }


        }

        return res + days - E;
    }
};