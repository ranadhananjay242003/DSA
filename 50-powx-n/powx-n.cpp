class Solution {
public:
    double myPow(double x, int n) {
        /*double ans = 1.0;
        long long power = abs((long long)n);
        for(int i = 0; i<power ; i++){
                ans = ans * x;
        }
        if(n < 0){
            ans = 1 / ans;
        }

        return ans;*/

        long long N = n; // Use long long to handle INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        while (N) {
            if (N % 2 == 1) {
                ans *= x;
            }
            x *= x;
            N /= 2;
        }

        return ans;
        
    }
};