class Solution {
public:
    vector<int> pascalTriangle(int N) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < N; col++) {
            ans *= (N - col);
            ans /= col;
            ansRow.push_back((int)ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(pascalTriangle(i));
        }
        return ans;
    }
};