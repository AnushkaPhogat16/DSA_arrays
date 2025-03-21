class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows= matrix.size();
        int cols = matrix[0].size();

        int dir = 0;
        // if dir = 0 -> l to r AND top++
        // if dir = 1 -> top to bot AND right--
        // if dir = 2 -> r to l AND bot--
        // if dir = 3 -> bot to top AND left++

        int left = 0;
        int top = 0;
        int right = cols - 1;
        int bot = rows - 1;

        while(top <= bot && left <= right){
            if(dir == 0){
                for(int j = left; j <= right; j++){
                    result.push_back(matrix[top][j]);
                }

                top++;
            }
            
            if(dir == 1){
                for(int i = top; i <= bot; i++){
                    result.push_back(matrix[i][right]);
                }

                right--;
            }

            if(dir == 2){
                for(int j = right; j >= left; j--){
                    result.push_back(matrix[bot][j]);
                }

                bot--;
            }

            if(dir == 3){
                for(int i = bot; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }

                left++;
            }

            dir++;

            if(dir == 4){
                dir = 0;
            }
        }

        return result;


    }
};