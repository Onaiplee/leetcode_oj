// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

/*
 * I will add comments later. There is better solution than this.
 */

class Solution {
    
public:
    int climbStairs(int n) {
        int *buf = (int *) malloc ((n + 1) * sizeof(int));
        int result;
        for (int i = 0; i < n + 1; i++) {
            buf[i] = 0;
        }
        buf[0] = 1;
        buf[1] = 1;
        for(int i = 2; i < n + 1; i++) {
            buf[i] = buf[i-1] + buf[i-2];
        }
        result = buf[n];
        free(buf);
        return result;
    }
};
