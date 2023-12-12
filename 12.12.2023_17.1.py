try:
    def stepen(x, n):
        x1=1
        for i in range(n):
            x1=x1*x
        return x1
    def F(k, a):
        res=stepen(2.7, k)+stepen(a+1, -5)
        return(res)
    k=int(input("Введите К: "))
    a = float(input("Введите a: "))
    print("ответ:", F(k, a))
except:
    print("Ошибка!")