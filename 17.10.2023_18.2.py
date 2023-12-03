print('введите Ox')
Ox=int(input())
print('введите Oy')
Oy=int(input())
if (Oy==0) or (Ox==0):
    print('ошибка ввода')
if (Oy>0) and (Ox>0):
    print('координата находится в 1 четверти')
if (Oy>0) and (Ox<0):
    print('координата находится в 2 четверти')
if (Oy<0) and (Ox<0):
    print('координата находится в 3 четверти')
if (Oy<0) and (Ox>0):
    print('координата находится в 4 четверти')
