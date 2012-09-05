// Given a collection of intervals, merge all overlapping intervals.
// 
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), &myfunction);
        deque<Interval> dq;
        vector<Interval> result;
        
        if (intervals.size() == 0) {
            return result;
        }

        // add a pivot
        dq.push_back(Interval(INT_MIN, INT_MIN + 1));
        for(int i = 0; i < intervals.size();) {
            if (intervals[i].start > dq.back().end) {
                dq.push_back(intervals[i]);
                i++;
            }
            else if (intervals[i].start <= dq.back().end && intervals[i].start >= dq.back().start) {
                dq.back().end = intervals[i].end;
                i++;
            }
            else {
                dq.pop_back();
            }
        }
        // remove the pivot
        dq.pop_front();
        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }
        return result; 
    }

    bool static myfunction(Interval i, Interval j) { return (i.end < j.end); }
};
