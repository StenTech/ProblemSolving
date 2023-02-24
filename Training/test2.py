n, m = map(int, input().split())
m_tab = list(map(int, input().split()))
i = 0
sub = []
res = []
while( i < m-1 ):
  if m_tab[i+1] == m_tab[i] + 1 : 
    sub.append(m_tab[i])
    sub.append(m_tab[i+1])
    
  else : 
    sub.append(m_tab[i])
    sub.append(m_tab[i]+1)
    
  res += sub[::-1]
  sub = []
  i += 1
  
print(*res)