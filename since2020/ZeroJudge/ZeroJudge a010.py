'''
	@judge ZeroJudge
	@id a010
	@name 因數分解

	@tag Integer Factorisation
'''
from sys import stdin
from itertools import chain, count, cycle

def factorIter():
	yield 2
	yield 3
	for gen in cycle([ iter(count(5, 6)), iter(count(7, 6)) ]):
		yield next(gen)

def factorisation(n):
	for x in factorIter():
		if n <= 1:
			return
		if x * x > n:
			yield (n, 1)
			return
		cnt = 0
		while n % x == 0:
			cnt += 1
			n //= x
		if cnt > 0:
			yield (x, cnt)

def output(ls):
	return ' * '.join(map(lambda p: f'{p[0]}^{p[1]}' if p[1] > 1 else str(p[0]), ls))

print('\n'.join([ output(factorisation(int(line))) for line in stdin ]))