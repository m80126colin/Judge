'''
	@judge UVa
	@id 10473
	@name Simple Base Conversion

	@tag Number Base Conversion
'''
from sys import stdin

res = [ f'0x{int(line):X}' if line.count('x') == 0 else str(int(line, 16))
	for line in stdin.readlines()
	if line.count('-') == 0 ]

print('\n'.join(res))