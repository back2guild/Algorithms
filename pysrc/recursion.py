"""
    Define recursive functions
"""
from sys import argv

def factorial(num):
    assert (num >= 1)
    if num == 1:
        return 1
    else:
        return num * factorial(num - 1)

"""
def main_factorial(cmdArgs):
    assert(len(cmdArgs) == 2)
    num = int(cmdArgs[1])
    print(f"factorial of {num} is {factorial(num)}")
    

if __name__ == "__main__":
    main_factorial(argv)

"""