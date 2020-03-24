'''
	@judge CodeForces
	@id 1327B
	@name Princesses and Princes
	@contest Educational Codeforces Round 84

	@tag Greedy, Graph Theory
'''
from sys import stdin

def solve(graph):
	m = max(map(lambda g: max(g) if len(g) else 0, graph))
	prince   = set(range(1, m + 2))
	princess = set()
	for idx, edges in enumerate(graph):
		target = prince & edges
		if len(target) == 0:
			princess |= set([ idx + 1 ])
		else:
			prince -= set([ min(target) ])
	if len(princess) == 0:
		print('OPTIMAL')
	else:
		print('IMPROVE')
		print('{} {}'.format(min(princess), min(prince)))
	return

input()
for line in stdin:
	n = int(line)
	graph = [ set(list(map(int, stdin.readline().split()))[1:]) for _ in range(n) ]
	solve(graph)