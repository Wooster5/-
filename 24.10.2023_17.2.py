try:
    from math import *
    X0=float(input('Введите X0: '))
    X1=float(input('Введите X1: '))
    dX=float(input('Введите dX: '))
    #  X0=float
    #  X1=float
    #  dX=float
    x=0
    if X0<X1:
        x=X0
    if X0>X1:
        x=X1
    z=0
    if X0==X1:
        print('Невозможно протабулировать')
    if X0<X1:
        while x<=X1:
            if x<0:
                z=x**2
            if (x>0) and (x<=1):
                z=sin(x)
            if (x>1):
                z=cos(x)
            print('Результат "x": ', x, ', pезультат "z": ', z)
            x=x+dX
    if X0>X1:
        while x<=X0:
            if x<0:
                z=x**2
            if (x>0) and (x<=1):
                z=sin(x)
            if (x>1):
                z=cos(x)
            print('Результат "x": ', x, ', pезультат "z": ', z)
            x=x+dX
except:
    print ('Ошибка ввода')



        
        
        
