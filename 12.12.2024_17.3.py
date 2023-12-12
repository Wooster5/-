def step(n):
    if n == 1:
        return "YES"
    elif n % 2 == 0:
        return step(n // 2)
    else:
        return "NO"

try:
    n=int(input("Введите N:"))
    print(step(n))
except:
    print("Ошибка")