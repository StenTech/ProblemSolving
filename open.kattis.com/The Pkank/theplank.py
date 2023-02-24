def plank(n) :
    if (n < 0) : return 0
    if (n == 0) : return 1
    return  plank(n-1) + plank(n-2) + plank(n-3)


def main() :
    n = int(input())
    print(plank(n))
    
if __name__ == "__main__" :
    main()