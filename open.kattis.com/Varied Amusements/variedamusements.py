MODULO = 1000000007

def A(n) :
    if n == 0 : return 1
    return b*B(n-1) + c*C(n-1)
    
def B(n) :
    if n == 0 : return 1
    return a*A(n-1) + c*C(n-1)
    
def C(n) : 
    if n == 0 : return 1
    return a*A(n-1) + b*B(n-1)
    
def process(n) :
    return a*A(n-1) + b*B(n-1) + c*C(n-1)
    
    
def main() : 
    global a, b, c
    n, a, b, c = map(int, input().split())
    print(process(n)%MODULO)
    

if __name__ == "__main__" :
    main()