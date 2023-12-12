#try:
N=int(input("Введите количество рек: "))
K=0
K=N
river=[]
for i in range(0, N):
    river.append(str(input(f"Введите реку {i+1}: ")))
    if ' ' in river:
        quit()
dict={"Россия":"Нева", "Германия":"Райн", "США":"Миссисипи"}
for i in range(0, K):
     print("Страна:", dict[river(i)])
#except:
 #   print("Ошибка")