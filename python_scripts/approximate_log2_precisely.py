import sys
import matplotlib.pyplot as plt
import numpy as np
from math import log2, log10
import struct

def ftob(num):
	return ''.join('{:0>8b}'.format(c) for c in struct.pack('!f', num))
def btoi(num):
	return int(num, 2)
def ftoi(num):
	return btoi(ftob(num))

def btof(b):
    bf = itob(int(b, 2))  # 4 bytes needed for IEEE 754 binary64.
    return struct.unpack('>d', bf)[0]
def itob(n):
    return n.to_bytes(4, 'little');
def itof(num):
	return btof(itob(num))

PRECISION = 1000000

MIN = 0.1
MAX = 10.0

MIN_FLOAT = 2**(-126)
MAX_FLOAT = 2127*(2 - 2**(-23))

x = np.linspace(MIN, MAX, PRECISION)
y_log2 = [log2(p) for p in x]
y_float = [ftoi(p) for p in x]

B = log2(MIN_FLOAT) - (log2(MAX_FLOAT) - log2(MIN_FLOAT))*ftoi(MIN_FLOAT)/(ftoi(MAX_FLOAT) - ftoi(MIN_FLOAT))
A = (log2(MAX_FLOAT) - log2(MIN_FLOAT)) / (ftoi(MAX_FLOAT) - ftoi(MIN_FLOAT))

print(f"A = {A} : {hex(ftoi(A))}")
print(f"B = {B} : {hex(ftoi(B))}")
print(f"-3B/2A = {-(3*B)/(2*A)} : {hex(ftoi(-(3*B)/(2*A)))}")

y_float = [A*p + B for p in y_float]

plt.plot(x, y_log2, label="log2(btof(v))")
plt.xlabel("btof(v)")
plt.plot(x, y_float, label="A*btoi(v) + B")
plt.legend()
plt.show()