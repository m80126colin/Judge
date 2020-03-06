'''
	@judge CodeForces
	@id 785A
	@name Anton and Polyhedrons

	@tag Counting
'''
face = dict(
	Tetrahedron=4,
	Cube=6,
	Octahedron=8,
	Dodecahedron=12,
	Icosahedron=20
)

n   = int(input())
res = sum([ face[input()] for x in range(n) ])

print(res)