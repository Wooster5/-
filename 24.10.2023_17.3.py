try:
    N=int(input('Введите N '))
    #  N=float
    sqr=0
    if N<1 :
        print('Ошибка ввода')
    for i in range(1, N+1):
        sqr=sqr+(2*i-1)
        print(sqr)
except:
    print ('Ошибка ввода')
    
