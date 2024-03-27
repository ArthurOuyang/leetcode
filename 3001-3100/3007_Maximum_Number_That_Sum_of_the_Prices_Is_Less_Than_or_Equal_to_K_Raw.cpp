class Solution {
public:
    long long gsb(long long i) {
        if (i == 0)
            return 0;
        
        long long ans = 1;

        while (i > 1) {
            i >>= 1;
            ans <<= 1;
        }

        return ans;
    }

    unordered_map<long long, unordered_map<long long, long long>> mp;

    // find occurences of x in binary representation in i <= num
    long long occurence(long long num, long long x) {
        long long k = gsb(num);

        if (k < x)
            return 0;
        else if (k == x)
            return num - x + 1;
        else {
            long long a = mp.find(num - k) != mp.end() && mp[num - k].find(x) != mp[num - k].end() ? mp[num - k][x] : occurence(num - k, x);
            long long b = mp.find(k - 1) != mp.end() && mp[k - 1].find(x) != mp[k - 1].end() ? mp[k - 1][x] : occurence(k - 1, x);
            return (mp[num - k][x] = a) + (mp[k - 1][x] = b);
        }
    }

    long long findMaximumNumber(long long k, int x) {
        long long low = 0, high = LLONG_MAX / 2;

        while (low < high) {
            long long mid = (low + high + 1) / 2, sum = 0;
            
            for (int i = 1; i * x <= 63; ++ i) {
                if ((mid >> (i * x - 1)) < 1)
                    break;
                
                long long f = 1LL << (i * x - 1);
                sum += occurence(mid, f);

                if (sum > k)
                    break;
            }

            if (sum > k)
                high = mid - 1;
            else
                low = mid;
        }

        return low;
    }
};
