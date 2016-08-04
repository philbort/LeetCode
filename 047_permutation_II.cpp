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
    /* The swapping method is based on the array is sorted. 
       If passing by reference, after swapping the array is NOT sorted anymore.
       So we have to do additional bookkeeping to make sure we are not swapping
       the duplicates.
   */
	void permutation( vector<int>& nums, int ind, vector<vector<int>>& result) {
		if (ind >= nums.size() - 1) {
			result.push_back(nums);
			return;
		}
		for (int i = ind; i < nums.size(); i++) {
		    // We do the regular check
		    if ( i != ind && nums[ind] == nums[i])
		        continue;
		    // Then we make sure the current number
		    // hasn't been swapped before.
            bool duplicate = false;
	        if(i != ind){
	            for(int j = ind; j < i; j++) {
	                if(nums[j] == nums[i]) {
	                    duplicate = true;
	                    break;
	                }
	            }
	        }
	        if(!duplicate) {
		        swap( nums[ind],nums[i]);
    			permutation(nums, ind+1, result);
    			swap(nums[i], nums[ind]);
	        }
		}
	}
};

/*
     pass by value here:
       The swapping method is based on the array is sorted. 
       If passing by value, bookkeeping is much easier, we don't need to 
       swap back.
    
	void permutation( vector<int> nums, int ind, vector<vector<int>>& result) {
		if (ind >= nums.size() - 1) {
			result.push_back(nums);
			return;
		}
		for (int i = ind; i < nums.size(); i++) {
		    if ( i != ind && nums[ind] == nums[i])
		        continue;
		    std::swap( nums[ind],nums[i]);
			permutation(nums, ind+1, result);
		}
	}
*/
