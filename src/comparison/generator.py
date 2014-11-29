
from random import randint
import sys

def random_list(n, k):
    lst = []
    for i in range(n):
        lst.append(randint(1, k))
    return ' '.join([str(x) for x in lst])

N = int(sys.argv[1]) if len(sys.argv) > 1 else 1500
n = int(sys.argv[2]) if len(sys.argv) > 2 else 1200
k = int(sys.argv[3]) if len(sys.argv) > 3 else 30

lists = []

for i in range(N):
    lists.append(random_list(n, k))

print(N, n, k)
print(*lists, sep='\n')

