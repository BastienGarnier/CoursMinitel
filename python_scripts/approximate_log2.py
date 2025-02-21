import sys
import matplotlib.pyplot as plt
import numpy as np
from math import log2, log10, log
import struct

def ftob(num):
	return ''.join('{:0>8b}'.format(c) for c in struct.pack('!f', num))
def btoi(num):
	return int(num, 2)
def int_of_float(num):
	return btoi(ftob(num))

PRECISION = 1000000

MIN = 0.1
MAX = 10.0

x = np.linspace(MIN, MAX, PRECISION)
y_log2 = [log2(p) for p in x]
y_float = [btoi(ftob(p)) for p in x]

A = 2**(-23)
B = -127

y_float = [A*p + B for p in y_float]

plt.plot(x, y_log2, label="log2(btof(v))")
plt.xlabel("btof(v)")
plt.plot(x, y_float, label="A*btoi(v) + B")
plt.legend()
plt.show()