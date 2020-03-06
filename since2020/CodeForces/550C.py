'''
	@judge CodeForces
	@id 550C
	@name Divisibility by Eight

	@tag Math, Trie
'''
class Trie:
	def __init__(self):
		self.table = dict()

	def makeTrie(self, key, node):
		if key == '':
			self.table['isleaf'] = node
			return
		fst = key[0]
		if fst not in self.table.keys():
			self.table[fst] = Trie()
		self.table[fst].makeTrie(key[1:], node)

	def insert(self, s):
		self.makeTrie(s, s)

def solve(trie, n):
	pointers = set([ trie ])
	for ch in n:
		news  = set([ p.table[ch] for p in pointers if ch in p.table.keys() ])
		check = list(filter(lambda p: 'isleaf' in p.table.keys(), news))
		if len(check) > 0:
			return check[0].table['isleaf']
		pointers = pointers | news
	return '-1'

res  = [ str(x) for x in range(1001) if x % 8 == 0 ]
root = Trie()
for x in res:
	root.insert(x)

n    = input()
ans  = solve(root, n)
flag = ans != '-1'

print('YES' if flag else 'NO')
if flag:
	print(ans)