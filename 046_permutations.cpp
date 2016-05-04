/*

46. Permutations

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/

class Solution {

public:

    vector<vector<int>> permute(vector<int>& nums) 
    {

    	vector<vector<int>> result;
    	if (nums.size() == 0)
    		return result;
    	permutation(nums, 0, result);
    	return result;
    }
private:

	void permutation( vector<int>& nums, int ind, vector<vector<int>>& result)
	{
		if (ind == nums.size() - 1)
		{
			result.push_back(nums);
			return;
		}
		for (int i = ind; i < nums.size(); i++)
		{
			std::swap( nums[ind],nums[i]);
			permutation(nums, ind+1, result);
			std::swap(nums[i], nums[ind]);
		}

	}

}