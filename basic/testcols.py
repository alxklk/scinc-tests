#!/usr/bin/python3

import sys

stdout=sys.stdout

for i in range(256):
	stdout.write("\033[38;5;%im"%(i))
	stdout.write("%03i "%(i))
	if i % 16 == 15:
		stdout.write("\n")
stdout.write("\033[0m")
stdout.write("\n")

for i in range(256):
	stdout.write("\033[48;5;%im"%(i))
	stdout.write("%03i "%(i))
	if i % 16 == 15:
		stdout.write("\033[0m")
		stdout.write("\n")
stdout.write("\033[0m")

stdout.write("\n")
