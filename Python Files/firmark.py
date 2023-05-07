from time import time
from numba import jit , prange , cuda
import asyncio

start = time()
@jit(parallel=True,fastmath=True,inline='always')
def primes_py(range_start , range_end):
    count_of_primes = 0
    range_start = range_start if range_start >=2 else 2
    for num in prange(range_start , range_end +1):
        for div_num in prange(2, num):
            if ((num % div_num) == 0 ):
                break
            else :
                count_of_primes += 1
    return count_of_primes

primes_py(0,2*10**7)

end = time()
print(f'it take {end - start} S')

# cpu 10**6 : it take 24.364680290222168 S
# cpu 10**6 : it take 23.455172777175903 S