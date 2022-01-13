class Solution {
public:
    struct number {
        int val, rept;
    };
    
    vector<number> input;
    vector<vector<int>> ans;
    int tar;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        tar = target;
        sort(candidates.begin(), candidates.end());
        input.push_back({candidates[0], 1});
        for (int i = 1; i < candidates.size(); ++ i) {
            if (candidates[i] != candidates[i - 1])
                input.push_back({candidates[i], 1});
            else
                ++ input[input.size() - 1].rept;
        }
        
        dfs(0, 0, {});
        return ans;
    }
    
    void dfs(int cur, int indx, vector<int> out) {
        if (cur == tar) {
            ans.push_back(out);
            return ;
        }
        
        for (int i = indx; i < input.size(); ++ i) {
            if (cur + input[i].val > tar)
                break;
            int j = 1;
            for (; j <= input[i].rept; ++ j) {
                if (cur + j * input[i].val > tar)
                    break;
                out.push_back(input[i].val);
                dfs(cur + j * input[i].val, i + 1, out);
            }
            
            for (; j > 1; -- j)
                out.pop_back();
        }
        
        return ;
    }
};
