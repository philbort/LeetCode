/*

46. Permutations

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> result;
    	if (nums.empty())   return result;
    	permutation(nums, 0, result);
    	return result;
    }
private:
	void permutation( vector<int>& nums, int ind, vector<vector<int>>& result) {
		if (ind == nums.size() - 1)
		{
			result.push_back(nums);
			return;
		}
		for (int i = ind; i < nums.size(); i++)
		{
			std::swap(nums[ind], nums[i]);
			permutation(nums, ind+1, result);
			std::swap(nums[i], nums[ind]);
		}
	}
};

/*
   bool nextPermutation(vector<int>& nums) {
        int k = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            return false;
        }
        int l = k+1;
        for (int i = nums.size() - 1; i > k+1; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
        return true;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (nextPermutation(nums))
            res.push_back(nums);
        return res;
    }
*/
