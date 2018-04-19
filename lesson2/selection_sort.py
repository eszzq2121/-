import random
import time

def random_int_list(start, stop, length):
    start, stop = (int(start), int(stop)) if start <= stop else (int(stop), int(start))
    length = int(abs(length)) if length else 0
    random_list = []
    for i in range(length):
        random_list.append(random.randint(start, stop))
    return random_list

def selectionsort(A,n):
    for i in range(0,n):
        minj=i
        minx=A[i]
        for j in range(i+1,n):
            if A[j]<minx:
                minx=A[j]
                minj=j
        A[minj]=A[i]
        A[i]=minx
    # return A

n=50000
randomList=random_int_list(1,100,n)
repeat_time=10
time_start=time.time()
for repeat in range(0,repeat_time):
    selectionsort(randomList,n)
    repeat=repeat+1
time_end=time.time()
time_spent=(time_end-time_start)/repeat_time
print "It took " + str(time_spent) +" seconds to run selectionsort at n="+ str(n)

