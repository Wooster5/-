from random import *
try:
    minel=100
    M=int(input("Введите М:" ))
    A=[]
    for i in range(M):
        A.append([randint(-10,10) for x in range(M)])
        print(A[i])
    for i in range(M):
        for j in range(M):
            if i>M-j-1:
                if (A[i][j])<minel:
                    minel=A[i][j]
    print("минимальный элемент ниже побочной диагонали:", minel)

except:
    print("ошибка")