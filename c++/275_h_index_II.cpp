/*

275. H-Index II

Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

*/

class Solution {

public:
    // Time: O(logn)
    // Space: O(1)
    int hIndex(vector<int>& citations) {
    	
        int size = citations.size();
        if(!size)   return 0;
        int left = 0, right = size - 1;
        
        /* (left <= right) and (right = mid)
           NOT (left < right ) and (right = mid +1)
           why?
        */
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (citations[mid] == size - mid)
                return size - mid;
            else if( citations[mid] < size - mid)
                left = mid+1;
            else
                right = mid-1;
        }
        return size - left;
    }
};

