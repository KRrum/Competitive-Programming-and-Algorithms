import sys

"""
classic merge sort
v - array
l - left
r - right
time complexity: O(nlogn)
extra memory: N

technically speaking, there is no need to use variables r1 and l2 in the merge function, because l2 = r1 + 1,
but I think it looks better when both variables are passed to the function

data: one line, where first number = amount of intigers in an array 
"""

def merge(v, l1, r1, l2, r2):
  l = l1
  r = r2 + 1
  R = []
  while(l1 <= r1 and l2 <= r2):
    if(v[l1] >= v[l2]):
      R.append(v[l1])
      l1+=1
    else:
      R.append(v[l2])
      l2+=1

  while(l1 <= r1):
    R.append(v[l1])
    l1+=1
  while(l2 <= r2):
    R.append(v[l2])
    l2+=1
  for i in range(l, r): v[i] = R[i - l]
#end def
def sorting(v, l, r): 
  if(l == r): return
  m = (l + r)//2
  sorting(v, l, m)
  sorting(v, m + 1, r)
  merge(v, l, m, m+1, r)
#end def
data = list(map(int, sys.stdin.read().split()))
n = data[0]
v = data[1:]

sorting(v, 0, n-1)
print(v)