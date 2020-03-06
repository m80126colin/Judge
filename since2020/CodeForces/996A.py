'''
	@judge CodeForces
	@id 996A
	@name Hit the Lottery

	@tag Simulation, Coin Change
'''
from functools import reduce

ls = [1, 5, 10, 20, 100]

def countBill(tup, curr):
	r, s = tup
	return (r % curr, s + r // curr)

def solve(n):
	r, res = reduce(countBill, ls[::-1], (n, 0))
	return res

n = int(input())

print(solve(n))