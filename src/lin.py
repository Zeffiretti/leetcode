names = ['小明', '小红', '小刚']

first_name = 0

for i in range(3):
    for j in range(len(names)):
        print(names[(j+i)%len(names)], end=' ')
        
    print()