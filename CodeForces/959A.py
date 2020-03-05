'''
	CodeForces 959A
	Mahmoud and Ehab and the even-odd game

	Proof:

	* n = 3:
		Mahmoud chooses 2, then n = 1
		Ehab chooses 1, then n = 0
		Ehab wins.
	* n = 4:
		Mahmoud chooses 4, then n = 0
		Mahmoud wins.

	Claim:
	* When n is even, Mahmoud chooses n, then Mahoud wins.
	* When n is odd, Mahmoud cannot turn into the state Ehab has no move, then Ehab wins.

	Tags: Game, Math
'''
n = input()

print('Mahmoud' if int(n[-1]) % 2 is 0 else 'Ehab')