// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

/*
 * This is a DP solution. However, it consume too much memory.
 * And there is not better than backtracking in time complexity.
 * In such problems that give all combinations, we favor Backtracking
 * over Dynamic Programming.
 */

class Solution {
public:
     vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > nil;
        vector<vector<int> >::iterator iter;
        vector<vector<int> > e;
        vector<int> pl;
        e.push_back(pl);
        int size = candidates.size();
        int last;
        vector<vector<vector<vector<int> > > > dist(size + 1, vector<vector<vector<int> > >(target + 1));
        for (int i = 1; i <= size; i++) {
          dist[i][0] = e;
        }
        
        for (int j = 1; j <= target; j++) {
          dist[0][j] = nil;
        }
        
        for (int i = 1; i <= size; i++) {
          for (int j = 1; j <= target; j++) {
            last = candidates[i-1];
            if (j >= last) {
              if (dist[i][j-last].size() != 0) {
                dist[i][j] = dist[i][j-last];
                for (iter = dist[i][j].begin(); iter < dist[i][j].end(); iter++) {
                  (*iter).push_back(last);
                }
                if (dist[i-1][j].size() != 0) {
                  for (iter = dist[i-1][j].begin(); iter < dist[i-1][j].end(); iter++) {
                    dist[i][j].push_back(*iter);
                  }
                }
              }
              else {
                dist[i][j] = dist[i-1][j];
              }
            }
            else {
              dist[i][j] = dist[i-1][j];
            }
          }
        }
        return dist[size][target];
    }
};
