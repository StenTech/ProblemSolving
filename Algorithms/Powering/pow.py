"""
dans ce module, nous allons implémenter des algorithmes d'exponention rapide.
"""


def quick_pow_1(x , n : int):
    """Exponention rapide avec la methode binaire la
         plus illustrée avec le SX
    """
    xSquare = x*x
    if (n == 1): return x
    elif(n%2 == 0): return quick_pow_1(xSquare, n/2)
    else : return x*quick_pow_1(xSquare, (n-1)/2)


def quick_pow_2(x, n : int): pass


def quick_pow_3(x, n : int):
    """Cette methode est  celle de l'arbre de knuth"""




# Test
if (__name__ == "__main__")  :
    print(pow(345, 34) == quick_pow_1(345,34))