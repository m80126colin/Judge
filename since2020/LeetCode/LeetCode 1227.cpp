/**
 *  @judge LeetCode
 *  @id 1227
 *  @name Airplane Seat Assignment Probability
 * 
 *  @tag Math
 */
class Solution {
public:
	double nthPersonGetsNthSeat(int n) {
		if (n == 1)
			return 1.0;
		return 0.5;
	}
};