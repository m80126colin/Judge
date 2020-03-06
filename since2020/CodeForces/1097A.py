'''
	@judge CodeForces
	@id 1097A
	@name Gennady and a Card Game

	@tag Ad-hoc, Card Game
'''
card = input()
hand = input().split()
res  = any(map(lambda x: x[0] is card[0] or x[-1] is card[-1], hand))

print('YES' if res else 'NO')