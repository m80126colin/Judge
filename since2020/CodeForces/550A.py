'''
	@judge CodeForces
	@id 550A
	@name Two Substrings

	@tag String manipulation
'''
s = input()

abH, abT = s.find('AB'), s.rfind('AB')
baH, baT = s.find('BA'), s.rfind('BA')

flag = (abH >= 0 and baT >= 0 and baT - abH > 1) or (abT >= 0 and baH >= 0 and abT - baH > 1)

print('YES' if flag else 'NO')