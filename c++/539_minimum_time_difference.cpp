/*

539. Minimum Time Difference

Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.

*/

class Solution {
public:
    // Time: O(nlogn)
    // Space: O(n)
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size(), res = 1440;
        vector<int> time(n);
        for(int i = 0; i < n; i++) {
            int hour = (timePoints[i][0] - '0') * 10 + 
                        timePoints[i][1];
            int min = (timePoints[i][3] - '0') * 10 + 
                        timePoints[i][4];
            time[i] = hour * 60 + min;
        }
        sort(time.begin(), time.end());
        
        for(int i = 1; i < n; i++)
            res = min(res, time[i] - time[i-1]);
        return min(res, 1440 + time[0] - time.back());
    }
};
