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
    // Time: O(n)
    // Space: O(n)
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
		    // Instead of only checking nums[ind] != nums[i]
		    // no we have to check every number before i.
		    bool duplicate = false;
                    // And since j = ind, j < i, i never equals ind
            	    // we don't have to check that anymore
	            for(int j = ind; j < i; j++) {
	                if(nums[j] == nums[i]) {
	                    duplicate = true;
	                    break;
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

/* Very cool method using hash table

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i]) == map.end())
                map[nums[i]] = 1;
            else
                map[nums[i]]++;
        }
    	vector<vector<int>> result;
    	vector<int> current;
    	permutation(nums.size(), current, map, result);
    	return result;
    }
    
private:
    void permutation(int size, vector<int>& current,
                     unordered_map<int, int>& map, vector<vector<int>>& result) {
        if(size <= 0){
            result.push_back(current);
            return;
        }
        for(auto &i : map) {
            if(i.second <= 0)
                continue;
            current.push_back(i.first);
            i.second--;
            permutation(size-1, current, map, result);
            current.pop_back();
            i.second++;
        }
                         
    }  
    
*/
