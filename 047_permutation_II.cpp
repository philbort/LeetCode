/*

47. Permutations I

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    	vector<vector<int>> result;
    	permutation(nums, 0, result);
    	return result;
    }
    
private:
	void permutation( vector<int> nums, int ind, vector<vector<int>>& result) {
		if (ind >= nums.size() - 1) {
			result.push_back(nums);
			return;
		}
		for (int i = ind; i < nums.size(); i++) {
		    if ( i != ind && nums[ind] == nums[i])// || nums[i] == nums[i-1]) )
		        continue;
		    std::swap( nums[ind],nums[i]);
			permutation(nums, ind+1, result);
			//std::swap(nums[i], nums[ind]);
		}
	}
};
