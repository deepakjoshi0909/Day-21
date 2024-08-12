#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return 0;
        }

        vector<int> ugly(n);
        ugly[0] = 1; 

        int i2 = 0, i3 = 0, i5 = 0;
        int nextUgly = 1;

        for (int i = 1; i < n; ++i) { 
            nextUgly = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));
            ugly[i] = nextUgly;

            if (nextUgly == ugly[i2] * 2) i2++;
            if (nextUgly == ugly[i3] * 3) i3++;
            if (nextUgly == ugly[i5] * 5) i5++;
        }

        return ugly[n - 1]; 
    }
};
