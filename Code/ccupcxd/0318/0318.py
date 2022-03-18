#  Author: D1stance || Bey0nd
#  Time: 2022-03-18 17:12:55

import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_string(): return sys.stdin.readline().strip()

n = int(input())

for i in range(n):
    x = list(get_ints())
    y = list(get_ints())
    for i in range(len(x)):
        x[i] = abs(x[i])
    for i in range(len(x)):
        y[i] = abs(y[i])
    x.sort()
    y.sort()
    ans = float()
    for i in range(len(x)):
        ans += (x[i] ** 2 + y[len(x) - i - 1] ** 2) ** (1 / 2)
    sys.stdout.write(str(int(ans)) + "\n")
    