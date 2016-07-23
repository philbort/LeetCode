/*

373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]

*/

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if(!m || !n || !k)
            return vector<pair<int, int>>();
        k = min(k, m*n);
        vector<pair<int, int>> result(k);
        
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        
        min_heap.emplace(0, 0);
        int i = 0;
        while(k-- > 0 && !min_heap.empty())
        {
            auto idx_pair = min_heap.top(); 
            min_heap.pop();
            result[i++] = make_pair(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < m)
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < n)
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};


/*  Use multimap:

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if(!m || !n || !k)
            return vector<pair<int, int>>();
        k = min(k, m*n);
        vector<pair<int, int>> result(k);
        multimap<int, pair<int, int>> map;    
        for (int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++)
                map.insert(make_pair(nums1[i] + nums2[j], make_pair(nums1[i], nums2[j])));
        }
        auto it = map.begin();
        for( int i = 0; i < k; i++) {
            result[i] = (it++->second);
        }
        return result;
    }
    
*/