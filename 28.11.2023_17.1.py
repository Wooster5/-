from random import *
try:
    s=0
    minelstrok=[]
    kolStrok = int(input("Введите количество строк:"))
    kolStolb = int(input("Введите количество столбцов:"))
    A = []
    for i in range(kolStrok):
        A.append([randint(-100, 100) for x in range(kolStolb)])
        print(A[i])
    for j in range(kolStrok):
        for i in range(kolStolb):
            if (A[j][i]%2==0) and (A[j][i]<0):
                s+=A[j][i]
        minelstrok.append([s])
        print(minelstrok)
        s=0
    n=len(minelstrok)
    for i in range(n):
        for j in range(n-i-1):
            if minelstrok[j] < minelstrok[j + 1]:
                temp = A[j]
                A[j] = A[j + 1]
                A[j + 1] = temp
                temp_char =minelstrok [j]
                minelstrok[j] = minelstrok[j + 1]
                minelstrok[j + 1] = temp_char
    for row in A:
        print(row)

except:
    print("ошибка")