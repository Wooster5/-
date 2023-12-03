try:
    A=float(input('Введите А: '))
    B=float(input('Введите B: '))

  #  A=float

    x=0
    if (A<0) or (B<0):
        x+=1
        print('Ошибка ввода')
    if (A<=B):
        x+=1
        print('Ошибка ввода')
    if x==0:
        while A>=B:
            A-=B
        print('Результат: ', A)
except:
    print ('Ошибка ввода')
