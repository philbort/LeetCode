/*

287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

class Solution {
public:
    // Basically binary search
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while(low < high)
        {
            int mid = low + (high - low)/2;
            int cnt = 0;
            for (int i = 0; i < nums.size();i++)
            {
                if(nums[i] <= mid)
                    cnt++;
            }
            if(cnt <= mid)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};

/*

O(n) solution:

See detailed explaination:

http://keithschwarz.com/interesting/code/find-duplicate/FindDuplicate.python.html

int findDuplicate3(vector<int>& nums)
{
    if (nums.size() > 1)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
    return -1;
}

*/