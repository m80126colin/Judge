/**
 *  @judge LeetCode
 *  @id 283
 *  @name Move Zeroes
 * 
 *  @tag Data Structure
 */
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (vector<int>::iterator it = remove(nums.begin(), nums.end(), 0); it != nums.end(); it++)
			*it = 0;
	}
};