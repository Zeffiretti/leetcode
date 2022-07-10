# input string str from terminal
str = input()
# input integer n from terminal
n = int(input())
for i in range(n):
    old_st = input()
    new_st = input()
    str = str.replace(old_st, new_st)
print(str)
