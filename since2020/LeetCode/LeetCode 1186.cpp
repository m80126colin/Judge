/**
 *  @judge LeetCode
 *  @id 1186
 *  @name Maximum Subarray Sum with One Deletion
 * 
 *  @tag Dynamic Programming, Greedy
 */
class Solution {
public:
	int maxWithNoDeletion(vector<int>& arr) {
		int ans = arr[0], tot = arr[0];
		for (int i = 1; i < arr.size(); i++) {
			tot = max(tot + arr[i], arr[i]);
			ans = max(ans, tot);
		}
		return ans;
	}
	int maxWithAtLeastOneDeletion(vector<int>& arr) {
		int ans = arr[0];
		int sumNoDel = arr[0];
		int sumAtLeastOneDel = arr[0];
		for (int i = 1; i < arr.size(); i++) {
			sumAtLeastOneDel = max(sumAtLeastOneDel + arr[i], sumNoDel);
			sumNoDel = max(sumNoDel + arr[i], arr[i]);
			ans = max(ans, max(sumNoDel, sumAtLeastOneDel));
		}
		return ans;
	}
	int maximumSum(vector<int>& arr) {
		int ans = this->maxWithAtLeastOneDeletion(arr);
		return ans;
	}
};