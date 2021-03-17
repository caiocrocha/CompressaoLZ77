# CompressaoLZ77
## Pseudocódigo
```
input string s
dict d = [(0,0,s[0])]
i = 1

while i < size(s)
    l = 1
    lL = 0 # largest number of matching chars
    lP = 0 # starting position of the match

    while l <= i
        count = 0
        prev = i-l
        next = i
        while prev < i and next < size(s) and s[prev] == s[next]
            prev += 1
            next += 1
            count += 1
        if count > lL
            lL = count
            lP = l
        l += 1
    
    d.add((lP, lL, s[i + lL]))
    i = i + lL + 1
```
## Exemplos
1. Entrada: "ababcbababaa"    
    Saída: [(0,0,"a"), (0,0,"b"), (2,2,"c"), (4,3,"a"), (2,2,"a")]