// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

/*
 * I will add some comments later. This problem is a good example to show how to reason the correctness of
 * a program.
 */ 

// Definition for an interval.
// struct Interval {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//     Interval(int s, int e) : start(s), end(e) {}
// };

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        int new_start;
        int new_end;
        int i;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i].end >= newInterval.start) {
                break;
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        if (i == intervals.size()) {
            result.push_back(Interval(newInterval.start, newInterval.end));
            return result;
        }
        
        new_start = intervals[i].start < newInterval.start ? intervals[i].start : newInterval.start;
        
        for (; i < intervals.size(); i++) {
            if (newInterval.end < intervals[i].start) {
                break;
            }
        }
        if (i == 0) {
            new_end = newInterval.end;
        }
        else {
            new_end = intervals[i-1].end > newInterval.end ? intervals[i-1].end : newInterval.end;
        }
        
        result.push_back(Interval(new_start, new_end));
        
        for (; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};
