try:
    s=[]
    n=int(input("Введите n:"))
    for i in range(0, n):
        s.append(float(input("Введите числа: ")))
        if ' ' in s:
            quit()
    lessthanC=0
    n=0
    numofpos=0
    counter=0

    C=(float(input("Введите С: ")))
    for i in s:
        counter+=1
        if i<C:
            lessthanC+=1
        if i<0:
            n=0
        if i>=0:
            n=n+(i//1)
            numofpos+=1
    if numofpos==counter:
        n=0
    print("Элементы меньше С:", lessthanC)
    print("Сумма целых частей элемента списка после последнего отрицательного:", n)
except:
    print("Ошибка")
