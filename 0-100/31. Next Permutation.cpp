class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 2) {
            swap(nums[0], nums[1]);
            return ;
        } else if (nums.size() == 1)
            return ;
        
        int i = nums.size() - 2;
        for (; i >= 0; -- i) {
            if (nums[i] >= nums[i + 1]) {
                if (i < nums.size() - 2) {
                    for (int j = nums.size() - 2; j > i; -- j)
                        if (nums[j] < nums[nums.size() - 1]) {
                            swap(nums[j], nums[nums.size() - 1]);
                            return ;
                        }
                }
                break;
            } else {
                swap(nums[i], nums[nums.size() - 1]);
                return ;
            }
        }
        -- i;
        for (; i >= 0; -- i) {
            if (nums[i] < nums[i + 1]) {
                int mn = nums[i + 1];
                int indx = i + 1;
                for (int j = i + 1; j < nums.size(); ++ j)
                    if (nums[j] < mn && nums[j] > nums[i]) {
                        indx = j;
                        mn = nums[j];
                    }
                swap(nums[i], nums[indx]);
                sort(nums.begin() + i + 1, nums.end());
                return ;
            }
        }
        
        sort(nums.begin(), nums.end());
    }
};