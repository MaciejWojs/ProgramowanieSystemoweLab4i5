#! /usr/bin/env python3
import sys

def rysujTrojkatRownoboczny(n, char):
    for i in range(n):
        print(f" " * (n - i - 1) + f"{char}" * (2 * i + 1))
        
def rysujTrojkatProst(n, char):
    for i in range(n):
        print(f"{char}" * (i + 1))
    
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python trojkat.py <n>")
        sys.exit(1)

    n = 5
    char = "*"
    param = int(sys.argv[1])
    if param == 1:
        rysujTrojkatRownoboczny(n, char)
    if param == 2:
        rysujTrojkatProst(n, char)
    