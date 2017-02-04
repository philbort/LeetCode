/*

239. Sliding Window Maximum

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

*/

class Solution {
	
public:
    // Time: O(n)
    // Space: O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || !k )  return vector<int> ();
        // Use a monotonic deque to store the index (not the actual number)
        deque<int> window;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // If we reach the size of the window, get rid of the oldest
            if (!window.empty() && window.front() == i-k) 
                window.pop_front();
            // Only save the ones big enough, so the deque is always 
            // monotonically increasing
            // including "=" here should save memory? (if (1,1,1) only enque one 1)
            while (!window.empty() && nums[window.back()] <= nums[i]) 
                window.pop_back(); // pop back here so never affect the front index
            window.push_back(i);
            // Save the actual number (not the index) for result
            if (i >= k - 1)
                ans.push_back(nums[window.front()]);
        }
        return ans;
    }
};
