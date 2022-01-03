class Solution {
public:
    
    /* 
        Static and Math
        Based on Legendre's 4-square theorem
        s.t every positive integer n is able to written in
        less or equal to sum of 4 squares.
    */
    int numSquares(int n) {
        // Static storage avoiding redundant calculations
        static vector<int> perfect({0});
        static unordered_map<int, int> mp;
        for (int i = sqrt(*(&perfect.back())) + 1; i * i <= 10000; ++ i) {
            perfect.push_back(i * i);
            ++ mp[i * i];
        }
        
        // If n is perfect square
        if (mp[n])
            return 1;
        
        // If n is sum of two squares
        for (int i = 1; i <= sqrt(n); ++ i)
            if (mp[n - perfect[i]])
                return 2;
        
        // Legendre's three-square theorem
        // iff n is not in form of 4^a(8b+7)
        while (!(n & 3))
            n >>= 2;
        
        if ((n & 7) == 7)
            return 4;
        
        return 3;
    }
};
