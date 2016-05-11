/*

347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

class Solution {

public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int num: nums)
            map[num]++;
        priority_queue<pair<int, int>> q;
        vector<int> ans(k,0);
        for (auto i = map.begin(); i != map.end(); i++)
            q.push(make_pair(i->second,i->first));
        // priority_queue doesn't have an iterator
        for (int i = 0; i < k; i++){ 
            ans[i] = q.top().second;
            q.pop();
        }
        return ans;
    }
};

/*  using bucket sort (selection sort also works):

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : cnt) {
            bucket[kv.second].push_back(kv.first);
        }

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
    
*/
