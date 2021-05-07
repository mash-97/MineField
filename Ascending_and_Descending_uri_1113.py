while True:
	string = input()
	string = string.split()
	string = [int(number) for number in string]
	x,y = string 
	
	if x>y:
		print("Decrescente")
	
	elif x<y:
		print("Crescente")
	
	else:
		break

