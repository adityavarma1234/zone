from itertools import *
open("input.txt","r+")
T = int(input())
c = 1
while(c<=T):
	x = input().split()
	a = x[0]
	b = int(x[1])
	a = ''.join(sorted(a))
	count = 0
	j=1
	while(1):
		for i in product(a,repeat=j):
			count = count + 1
			if(count==b):
				ans = ''.join(i)
				print("Case #",c,": ",ans)
				break
		if(count==b):
			break
		j = j + 1
	c = c + 1
