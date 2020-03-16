'''
	@judge CodeForces
	@id 381A
	@name Sereja and Dima

	@tag Simulation, Two Pointers, Card Game
'''
def solve(arr, n):
	L, R = 0, n - 1
	ans = [0, 0]
	for t in range(n):
		if arr[L] < arr[R]:
			ans[t & 1] += arr[R]
			R -= 1
		else:
			ans[t & 1] += arr[L]
			L += 1
	return ans

n = int(input())
arr = list(map(int, input().split()))

print(*solve(arr, n))