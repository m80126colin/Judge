'''
	@judge CodeForces
	@id 1145A
	@name Thanos Sort

	@tag recursion
'''
def checkSortedOrThanos(ms):
	if len(ms) == 1:
		return 1
	m = len(ms) // 2
	ln = checkSortedOrThanos(ms[:m])
	rn = checkSortedOrThanos(ms[m:])
	if m == ln and m == rn and ms[m - 1] <= ms[m]:
		return len(ms)
	return max(ln, rn)

n  = int(input())
ms = list(map(int, input().split()))

print(checkSortedOrThanos(ms))