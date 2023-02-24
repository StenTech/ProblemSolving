# Générate all subset of size 3 of ['+', '-', '*', '/']

opertors = ['+', '-', '*', '/']
 
def generate_all_subset_of_size_3():
    for i in range(4):
        for j in range(4):
            for k in range(4):
                yield [opertors[i], opertors[j], opertors[k]]
                
                
def main():
    
    generator = list(generate_all_subset_of_size_3())
    
    #print(len(list(generator)))
    
    m = int(input())
    
    for i in range(m) :
        target = int(input())
        for path in generator :
            calculus = "4 "
            for operation in path :
                calculus += operation + " 4 "
            calculus = calculus.replace("/", "//")
            result = eval(calculus)
            if (result == target) :
                calculus = calculus.replace("//", "/")
                print(calculus + " = " + str(target))
                break
            
        else :
            print("no solution")
        
        
        
if __name__ == "__main__":
    main()