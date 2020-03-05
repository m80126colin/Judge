'''
	CodeForces 1321A
	Contest for Robots

	Tags: Ad-hoc, Math
'''
input()
As = list(map(int, input().split()))
Bs = list(map(int, input().split()))
flag = len(list(filter(lambda x: As[x] > Bs[x], range(len(As)))))

print((sum(Bs) - sum(As)) // flag + 2 if flag != 0 else -1)