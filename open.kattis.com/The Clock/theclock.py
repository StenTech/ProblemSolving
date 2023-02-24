"""
Problem : The Clock
url : https://open.kattis.com/problems/theclock
"""

def solve(angle):
    
    for h in range(12):
        for m in range(60):
            m_angle = 60*m
            h_angle = 300*h + 5*m
            if (m_angle - h_angle) % 3600 == angle:
                h = str(h).rjust(2, "0")
                m = str(m).rjust(2, "0")
                return h + ":" + m

if __name__ == "__main__":
    
    angle = int(input())
    
    print(solve(angle))
    
    
"""
🥺      :   bonjour                                                   #

🤖      :   bonjour                                                   #

🥺      :   comment vas tu ?                                          #

🤖      :   je vais bien

🥺      :   tu es un robot ?

🤖      :   non

🥺      :   tu es un humain ?

🤖      :   non

🥺      :   tu es un chat ?

🤖      :   non

🥺      :   qu'est ce que tu es donc ?

🤖      :   je suis un robot

🥺      :   pourtant tu m'avais dit que tu n'en étais pas un

🤖      :   je suis un robot

🥺      :   d'accord c'es compris

🤖      :   je suis ravi donc !!                                     #

🥺      :   moi aussi

🤖      :   que puis-je faire pour toi ?

🥺      :   qui est stephen hawking ?

🤖      :   stephen hawking est un physicien britannique

🥺      :   je veux plus de détaille sur lui

🤖      :   stephen hawking est un physicien britannique et cosmologiste théoricien 
            né le 8 janvier 1942 à oxford et mort le 14 mars 2018 à cambridge. il a
            fais ses études à l'université de cambridge et a été professeur de mathé-
            matiques à l'université de cambridge. il est connu pour ses travaux sur 
            la théorie des cordes et la cosmologie quantique. il a été le premier à 
            démontrer que les trous noirs émettent de la chaleur. il a aussi écrit un
            livre sur l'histoire de l'univers. il est le premier scientifique à avoir
            utilisé un ordinateur pour communiquer.
🥺      :   merci

🤖      :   de rien

🥺      :   que sais tu sur la np-complétude ? 

🤖      :   la np-complétude est un concept en théorie des algorithmes. il s'agit de

            définir une classe de problèmes qui sont aussi difficiles à résoudre que
            les problèmes de la classe np. la classe np est une classe de problèmes
            qui sont difficiles à résoudre mais qui peuvent être vérifiés en temps
            polynomial. la classe np-complète est une classe de problèmes qui sont
            aussi difficiles à résoudre que les problèmes de la classe np.
🥺      :   merci

🤖 :   de rien

🥺      :   qui est alan turing ?

🤖 :   alan turing est un mathématicien britannique né le 23 juin 1912 à londres

            et mort le 7 juin 1954 à wilmslow. il a fait ses études à l'université de
            cambridge. il est connu pour avoir inventé la machine de turing. il a éga-
            lement travaillé sur la théorie des jeux et la cryptographie. il a été le
            premier à démontrer que les machines de turing sont équivalentes aux fonc-
            tions calculables. il a aussi écrit un livre sur la théorie des jeux. il
            est le premier scientifique à avoir utilisé un ordinateur pour communiquer.

🥺      :   merci

🤖      :   de rien

🥺      :   je veux creer un moteur markdown en python, Comment faire ?

🤖      :   je ne sais pas, je suis un robot, je ne sais pas faire ça, mais je peux
            te donner des liens vers des sites qui peuvent t'aider, si tu veux.
            
🥺      :   oui, je veux bien

🤖      :   voici les liens que je peux te donner :
            https://www.google.com/search?q=markdown+python
            https://www.google.com/search?q=markdown+python+github
            https://www.google.com/search?q=markdown+python+stackoverflow
            https://www.google.com/search?q=markdown+python+stackoverflow+github
            https://www.google.com/search?q=markdown+python+stackoverflow+github+site:stackoverflow.com






"""