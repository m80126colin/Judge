/**
 *  @judge LeetCode
 *  @id 27
 *  @name Remove Element
 * 
 *  @tag Data Structure
 */
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator it = remove(nums.begin(), nums.end(), val);
		nums.erase(it, nums.end());
		return nums.size();
	}
};