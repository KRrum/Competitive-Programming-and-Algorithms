import sys
"""
classic quick_sort
Time:
-   average complexity: O(nlogn)
-   worst case: O(n^2)
-   base case: O(nlogn)

"""
def sorting(T): 
    def find_pivot(T, l, r): #places pivot on last position using median of three
        mid = (l + r)//2
        if(T[l] > T[mid]): T[l], T[mid] = T[mid],T[l]
        if(T[mid] > T[r]): 
            T[mid], T[r] = T[r],T[mid]
            if(T[l] > T[mid]): T[l], T[mid] = T[mid],T[l]   
        T[r], T[mid] = T[mid], T[r]
    #end def
    def partition(T, l, r): #classic partition in quick_sort
        find_pivot(T, l, r)
        pivot = T[r]
        i = l - 1
        for j in range(l, r):
            if(T[j] <= pivot):
                i+=1
                T[j], T[i] = T[i], T[j]
        i+=1
        T[r], T[i] = T[i], T[r]
        return i
    def quick_sort(T, l, r): #quick sorts with recursion
        if(l < r):
            ind = partition(T, l, r)
            quick_sort(T, l, ind - 1)
            quick_sort(T, ind + 1, r)
    #end def

    l = 0
    r = len(T) - 1
    quick_sort(T, l, r)
#end def

input_data = sys.stdin.read().split()
if not input_data: exit()
n = int(input_data[0])
T = [int(x) for x in input_data[1:]]

sorting(T)
print(T)