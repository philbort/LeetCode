/*

401. Binary Watch

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        helper(result, make_pair(0, 0), num, 0);
        return result;
    }
private:
    const vector<int> hour = {1, 2, 4, 8};
    const vector<int> min = {1, 2, 4, 8, 16, 32};
    const int m = hour.size(), n = min.size();
    void helper(vector<string>& result, pair<int, int> time, int num, int start) {
        if(num == 0) {
            string cur = to_string(time.first) + ":" + 
                        ( (time.second < 10) ? "0":"") + 
                        to_string(time.second);
            result.push_back(cur);
            return;
        }
        for(int i = start; i < m + n; i++) {
            if(i < m) {
                time.first += hour[i];
                if(time.first < 12)
                    helper(result, time, num - 1, i + 1);
                time.first -= hour[i];
            }
            else {
                time.second += min[i - m];
                if(time.second < 60)
                    helper(result, time, num - 1, i + 1);
                time.second -= min[i - m];
            }
        }
    }
};
