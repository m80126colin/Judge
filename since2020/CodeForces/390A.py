'''
	CodeForces 309A
	Inna and Alarm Clock

	Tags: Counting
'''
n = int(input())

alert = [ tuple(input().split()) for i in range(n) ]
ans   = min(map(lambda x: len(set(x)), zip(*alert)))

print(ans)