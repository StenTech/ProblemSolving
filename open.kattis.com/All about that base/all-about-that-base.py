######################################################################
#                       Problem Description                          #
#                 Problem: All about that base                       #
#                 Link: https://open.kattis.com/problems/base        #
######################################################################

# a set of symbols that sort the symbols in the input, so that the first symbol is the smallest
# the symbols a alpahebetic, so we can use the set function to sort them

symbols = "&123456789abcdefghijklmnopqrstuvwxyz0"

maxnum = 2**32 - 1

# evaluate a number in a given base by converting it to base 10
def convert(n1, n2, n3, base):
    
    if base == 1 :
        if (len(set(n1)) == 1 and len(set(n2)) == 1 and len(set(n3)) == 1) and '1' in set(n1) and '1' in set(n2) and '1' in set(n3):
            return len(n1), len(n2), len(n3)
        else:
            return None
    
    try:
        value1 = int(n1, base)
        value2 = int(n2, base)
        value3 = int(n3, base)
        if value1 > maxnum or value2 > maxnum or value3 > maxnum:
            return None
        return value1, value2, value3
    except ValueError:
        return None

    

def evaluate(base, operator, operand1, operand2, operand3):
    values = convert(operand1, operand2, operand3, base)
    if values is None:
        return False
    
    (value1, value2, value3) = values
    result = {
        "+": value1 + value2,
        "*": value1 * value2,
        "-": value1 - value2,
        "/": value1 / value2,
    }[operator]
    return result == value3
    
def main() :
    
    n = int(input())
    
    for i in range(n):
        
        operand1, operator, operand2, _, operand3 = input().split()
        
        true_base = ""
        
        for i in range(1, 37):
            
            base = symbols[i]
            
            res = evaluate(i, operator, operand1, operand2, operand3)
            
            if res:
                true_base += base
                continue
                
        if true_base == "":
            print("invalid")
        else:
            print(true_base)
    
if __name__ == '__main__':
    main()
    
        