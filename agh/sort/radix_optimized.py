"""
High-Performance Radix Sort implementation for Python.
Optimized using:
- bitwise operations (>> and &) instead of arithmetic (// and %)
- array.array for memory efficiency

Complexity: O(N + sqrt(M)), where M is the maximum value in the array
M - maximum number in array
"""

import sys
from array import array

def count_sort(T, W, n, dzielnik, modulo, P, l): #classic stable count sort where %,// were replaced for bit operation to increase speed
    k = modulo-1
    Tl = T
    Wl = W
    Pl = P
    if(l):
        for i in range(modulo): Pl[i] = 0
    for i in range(n):
        x = (Tl[i] >> dzielnik) & (k) 
        Pl[x] += 1
    for i in range(1, modulo): Pl[i] += Pl[i - 1]

    for i in range(n-1, -1, -1):
        x = Tl[i]
        idx = (x >> dzielnik) & (k)
        Pl[idx] -= 1
        Wl[Pl[idx]] = x
#end def
def solve():
    def data():
        for line in sys.stdin:
            for word in line.split():
                yield word
    #end def
    line = data()
    n = int(next(line))
    T = array('i', [0] * n)
    for i in range(n): T[i] = int(next(line))
    najw = max(T)

    bits = 0
    l = 1
    while(l*l <= najw):
        l*=2
        bits+=1
    Mask = (1 << bits)
    W = array('i', (0 for _ in range(n)))
    P = array('i', (0 for _ in range(Mask)))
    #print(T, przesuniecie)
    count_sort(T, W, n, 0, Mask, P, False)
    count_sort(W, T, n, bits, Mask, P, True)
    print(T)
#end def

solve()