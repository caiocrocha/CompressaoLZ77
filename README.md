# CompressaoLZ77
Algoritmo de codificação LZ77 implementado para a disciplina de Estruturas de Dados II da Universidade Federal de Juiz de Fora (UFJF). 
## Instruções
```
make
./main nome_do_arquivo_de_entrada.txt
```
## Pseudocódigo
```
input string s
input int buffSize
input int dictSize
list keys = []

i = 0
while i < size(s)
    l = 1
    lL = 0 # largest number of matching chars
    lP = 0 # starting position of the match

    while l <= dictSize and l <= i
        count = 0
        prev = i-l
        next = i
        while buffSize >= next - i + 1 and s[prev] == s[next]
            if next == size(s)
                break
            prev += 1
            next += 1
            count += 1
        if count > lL
            lL = count
            lP = l
        l += 1
    
    i = i + lL + 1
    if i > size(s)
        keys.add((lP, lL, null))
    else
        keys.add((lP, lL, s[i-1]))
```
## Exemplos
1. Entrada: "ababcbababaa"    
    Saída: [(0,0,"a"), (0,0,"b"), (2,2,"c"), (4,3,"a"), (2,2,"a")]
