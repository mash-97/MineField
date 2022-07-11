n = int(input())

print(n, end="")
while(n>1):
	if((n&1)==0):
		n //= 2
	else:
		n = n*3+1
	print(" "+str(n), end="")

print()
