class Nucleotide:
    def __init__(self, nucleotide):
        self.nucleotide = nucleotide

    def __str__(self):
        return self.nucleotide

    def __repr__(self):
        return self.nucleotide

    def __eq__(self, other):
        return self.nucleotide == other.nucleotide

    def __hash__(self):
        return hash(self.nucleotide)
    

class Gene:
    def __init__(self) -> None:
        self.nucleotides = ""
        self.health = 0
        self.position = 0
        
    
    # surcharge du constructeur de la classe Gene
    def __init__(self, nucleotides: str) -> None:
        self.nucleotides = nucleotides
        self.health = 0
        self.position = 0
        
    def __init__(self, datas : tuple[str, int, int]) -> None:
        self.nucleotides = datas[0]
        self.health = datas[1]
        self.position = datas[2]
        
        
    
    def __str__(self) -> str:
        return str((self.nucleotides, self.health, self.position))
    
    def __repr__(self) -> str:
        return str((self.nucleotides, self.health, self.position))
    
    def __eq__(self, other) -> bool:
        return self.nucleotides == other.nucleotides and self.health == other.health and self.position == other.position
    
    def __hash__(self) -> int:
        return hash(self.nucleotides) + hash(self.health) + hash(self.position)
    
    def __contains__(self, nucleotide):
        return nucleotide in self.nucleotides
    
    def __len__(self):
        return len(self.nucleotides)
    
    def __iter__(self):
        return iter(self.nucleotides)
    
    def __next__(self):
        return next(self.nucleotides)
    
    def __getitem__(self, index):
        return self.nucleotides[index]
    
    def __setitem__(self, index, value):
        self.nucleotides[index] = value
    
    def __delitem__(self, index):
        del self.nucleotides[index]
    