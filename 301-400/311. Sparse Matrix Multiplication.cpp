class Solution {
public:
    // coordinate format
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector<int>> m1;
        vector<vector<int>> m2;
        vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size()));
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        
        for (int i = 0; i < mat1.size(); ++ i) {
            for (int j = 0; j < mat1[0].size(); ++ j) {
                if (mat1[i][j]) {
                    if (rows.find(i) == rows.end())
                        rows[i] = m1.size();
                    m1.push_back({i, j, mat1[i][j]});
                }
            }
        }
        
        for (int i = 0; i < mat2[0].size(); ++ i) {
            for (int j = 0; j < mat2.size(); ++ j) {
                if (mat2[j][i]) {
                    if (cols.find(i) == cols.end())
                        cols[i] = m2.size();
                    m2.push_back({j, i, mat2[j][i]});
                }
            }
        }
        
        int indx1 = 0, indx2 = 0;
        for (int i = 0; i < ans.size(); ++ i) {
            indx1 = rows[i];
            for (int j = 0; j < ans[0].size(); ++ j) {
                indx2 = cols[j];
                for (int ii = indx1, jj = indx2; ii < m1.size() && jj < m2.size() && m1[ii][0] == i && m2[jj][1] == j;) {
                    if (m1[ii][1] == m2[jj][0]) {
                        ans[i][j] += m1[ii][2] * m2[jj][2];
                        ++ ii;
                        ++ jj;
                    } else if (m1[ii][0] < m2[jj][1])
                        ++ ii;
                    else
                        ++ jj;
                }
            }
        }
        
        return ans;
    }
};
