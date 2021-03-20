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
input int tamBuffer
input int tamDicio
list keys = []

i = 0
while i < size(s) // percorre o comprimento da string
    l = 1 // numero de chars a serem subtraidos
    maiorL = 0 // comprimento da maior sequencia de chars iguais
    maiorP = 0 // posicao inicial da sequencia

    while l <= tamDicio and l <= i // percorre a sequencia anterior
        cont = 0 // contador do numero de chars iguais
        anterior = i-l // posicao do char de comparacao anterior
        atual = i // posicao do char de comparacao atual
        while tamBuffer >= atual - i + 1 and s[anterior] == s[atual] // avanca na string enquanto os dois chars de comparacao forem iguais
            if atual == size(s)
                break
            anterior += 1
            atual += 1
            cont += 1
        if cont > maiorL // atualiza sequencia de maior comprimento se ela contem mais numeros iguais
            maiorL = cont
            maiorP = l
        l += 1
    
    i = i + maiorL + 1 // atualiza a posicao atual
    if i > size(s)
        keys.add((maiorP, maiorL, null))
    else
        keys.add((maiorP, maiorL, s[i-1]))
```
## Exemplos
1. Entrada: "ababcbababaa"    
    Saída: [(0,0,"a"), (0,0,"b"), (2,2,"c"), (4,3,"a"), (2,2,"a")]
