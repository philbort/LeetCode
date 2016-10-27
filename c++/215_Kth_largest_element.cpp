/*

215. Kth Largest Element in an Array  

Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/

class Solution {

public:

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (left <= right){
        	// quicksort
            int pos = partition(nums,left,right);
            if( pos == k-1 )
                return nums[pos];
            else if( pos > k-1 )
                right = pos;
            else
                left = pos+1;
        }
        return nums[left];
    } 
    
private:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};


/* above method is better than this on average for big vectors:

    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),std::greater<int>());
        return nums[k-1];
    }
    
*/
    