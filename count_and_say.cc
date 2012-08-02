// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

/*
 * I will add some comments later.
 */

class Solution {
public:
    string countAndSay(int n) {
        n = n - 1;
        queue<int> q1;
        queue<int> q2;
        queue<int> *qs[2];
        qs[0] = &q1;
        qs[1] = &q2;
        queue<int> *src = NULL;
        queue<int> *dsc = qs[0];
        int count;
        int current;
        q1.push(1);
        for (int i = 0; i < n; i++) {
            src = qs[i % 2];
            dsc = qs[(i + 1) % 2];
            current = src->front();
            src->pop();
            count = 1;
            while (!src->empty()) {
                if (src->front() == current) {
                    src->pop();
                    count++;
                }
                else {
                    dsc->push(count);
                    dsc->push(current);
                    current = src->front();
                    src->pop();
                    count = 1;
                }
            }
            dsc->push(count);
            dsc->push(current);
        }
        ostringstream os(ostringstream::out);
        while (!dsc->empty()) {
            os << dsc->front();
            dsc->pop();
        }
        return os.str();
        
    }
};
