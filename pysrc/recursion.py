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
    

class Stack(object):
    def __init__(self) -> None:
        self.stack = []
    
    def push(self,item):
        self.stack.append(item)
    
    def pop(self):
        if self.empty() is False:
            return self.stack.pop()
        else:
            return True
    
    def empty(self):
        return (len(self.stack) == 0)
    
    def size(self):
        return len(self.stack)
    
    def __str__(self) -> str:
        return self.stack
    

def tower(N: int, A : Stack, B : Stack, C : Stack):
    if N == 1:
        print ("Move disk 1 from source",A,"to destination",C)
        C.push(A.pop())
        return
    
    # move N - 1 from 
    


def main():
    pA = Stack()
    pA.append(1)
    pA.append(2)
    pA.append(3)
    pB = Stack()
    pC = Stack()
    tower(3, pA, pB, pC)


if __name__ == "__main__":
    main()

"""
def main_factorial(cmdArgs):
    assert(len(cmdArgs) == 2)
    num = int(cmdArgs[1])
    print(f"factorial of {num} is {factorial(num)}")
    

if __name__ == "__main__":
    main_factorial(argv)

"""