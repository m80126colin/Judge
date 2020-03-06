'''
	@judge CodeForces
	@id 309A
	@name Inna and Alarm Clock

	@tag Counting
'''
n = int(input())

alert = [ tuple(input().split()) for i in range(n) ]
ans   = min(map(lambda x: len(set(x)), zip(*alert)))

print(ans)