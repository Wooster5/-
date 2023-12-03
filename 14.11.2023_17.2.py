s=str(input("Введите текст: "))
latin="abcdefghijklmnopqrstuvwxyz"
rus="абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
count=0
for i in s:
    if i in latin:
        count+=1
    if i in rus:
        count+=1
print(count)