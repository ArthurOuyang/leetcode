class Solution {
public:
    
    // static and math
    int numSquares(int n) {
        static vector<int> perfect({0});
        static unordered_map<int, int> mp;
        for (int i = sqrt(*(&perfect.back())) + 1; i * i <= 10000; ++ i) {
            perfect.push_back(i * i);
            ++ mp[i * i];
        }
        
        if (mp[n])
            return 1;
        
        for (int i = 1; i <= sqrt(n); ++ i)
            if (mp[n - perfect[i]])
                return 2;
        
        while (!(n & 3))
            n >>= 2;
        
        if ((n & 7) == 7)
            return 4;
        
        return 3;
    }
};
