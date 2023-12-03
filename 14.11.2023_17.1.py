try:
    s=str(input("Введите текст: "))+' '
    word=str(input("Введите слово: "))
    count=0
    n=''
    b=[]
    for i in s:
        if ' ' not in i:
            n+=i
        elif n!='':
            if n[len(n) - 1] in ',.!?':
                n = n[0:len(n) - 1]
            b.append(n)
            n=''
    for i in b:
        if i==word:
            count+=1
    print ("Число найденных слов:", count)
except:
    print("Ошибка!!!")