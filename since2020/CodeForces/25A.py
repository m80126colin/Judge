'''
	@judge CodeForces
	@id 25A
	@name IQ test

	@tag Ad-hoc
'''
input()
s = ''.join(list(map(lambda x: str(int(x) % 2), input().split())))

print((s.find('0') if s.count('0') == 1 else s.find('1')) + 1)