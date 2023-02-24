from email.policy import default


def parent(node, tree : dict):
    if(node != None) : return tree[node][0]

def knuth_tree(nb_couche: int ) -> dict:
    """construire un arbre à nb_couche de knuth couche"""
    
    #knt = {1 : [2], 2 : [3, 4], 3 : [5, 6], 4 : [8]}
    #knt = {1 : {2]}
    #knt = {1 : (None, [2]) , 2 : (1, [3, 4])}
    #knt = {1 : (None, [2]) , 2 : (1, [3, 4]), 4 : (2, [8])}
    knt = {1 : (None, [2])}
    existingNode = {1 : 0, 2: 0}
    #existingNode = {1 : 0, 2 : 0, 3 : 0, 4 : 0, 8 : 0}
    #existingNode = {1 : 0, 2 : 0, 3 : 0, 4 : 0}


    

    for i in range(nb_couche-2):

        knt_cp = knt.copy()
        
        for k in knt_cp:
        
            for node in  knt_cp[k][1]:
        
                nodes = []
        
                if(knt.get(node)==None) : 
                    knt[node] = (k, nodes)
                    parentNode = node  
        
                    while (parentNode != None):
                        _node = node + parentNode
                        if(existingNode.get(_node) == None) : 
                            nodes.append(_node)
                            existingNode[_node] = 0
                        
                        parentNode = parent(parentNode, knt)                    
                    else : 
                        #nodes.append(node*2)
                        #knt[node] = (k, nodes)
                        nodes.reverse()
                        #for k in nodes : knt[k] = (node, [])
                        #pass
                    print({node:nodes})  

    return knt


# Test
if (__name__ == "__main__") :
    muTree = (knuth_tree(7))
    #for k in muTree :
    #    print(k, muTree[k], sep=' : ')