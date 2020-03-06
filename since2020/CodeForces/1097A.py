'''
	CodeForces 1097A
	Gennady and a Card Game

	Tags: Ad-hoc, Card Game
'''
card = input()
hand = input().split()
res  = any(map(lambda x: x[0] is card[0] or x[-1] is card[-1], hand))

print('YES' if res else 'NO')