def IsLeapYear(Y):
    if (Y % 4 == 0) and (Y % 100 != 0 or Y % 400 == 0):
        return True
    else:
        return False
try:
    for i in range(5):
        Y=int(input("Введите год: "))
        if Y<0: print("Ошибка")
        print(IsLeapYear(Y))
except:
    print("Ошибка")
