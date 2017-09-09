import sys

temp = (sys.stdin.read())
a = (temp.split('\n'))

a1= int(a[0])
a2 = int(a[1])
a3 = int(a[2])
a4 = int(a[3])
index=0
max=max(a1,a2,a3,a4)
for i in range(0,4,1):
	if max == int(a[i]):
		index=i
print(str(index)+' '+str(max))