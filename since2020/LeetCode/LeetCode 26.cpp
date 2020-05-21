/**
 *  @judge LeetCode
 *  @id 26
 *  @name Remove Duplicates from Sorted Array
 * 
 *  @tag Data Structure
 */
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		vector<int>::iterator pos;
		pos = nums.begin();
		for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++)
			if (*it != *pos)
				*(++pos) = *it;
		nums.resize(pos - nums.begin() + 1);
		return nums.size();
	}
};