c = 6

def dump_func(a,b) -> tuple:
    a += 1
    b -= 1
    return (a,b)

if __name__ == "__main__":
    a = 3
    b = 5
    (a,b) = dump_func(a,b)
    print(f"a = {a}, b = {b}")
    (a,c) = dump_func(a,c)
    print(f"a = {a}, b = {c}") 