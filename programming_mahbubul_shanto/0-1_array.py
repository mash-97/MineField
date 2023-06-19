def biggest_square(square):
	n = len(square) # row
	m = len(square[0]) # column
	
	tally = [0 for e in range(0, m)]+[0]
	square_areas = []
	
	for row in square:
		tally = [[0, tally[i]+row[i]][row[i]] for i in range(0, m)]+[0]
		stack = []
		print(f"array: {str(row)}, tally: {str(tally)}")
		for indx, element in enumerate(tally):
			t_indx = -1
			while(len(stack)>0 and stack[len(stack)-1][0] > element):
				sv, si = stack.pop()
				area = (indx-si) * sv
				square_areas.append(area)
				t_indx = si
			
			if t_indx != -1:
				stack.append((element, t_indx))
			else:
				stack.append((element, indx))
	
	print(f"stack areas: {str(square_areas)}")
	if len(square_areas)!=0: return max(square_areas)
	return 0


if __name__ == '__main__':
	n = int(input("enter number of rows: "))
	square = []
	for _ in range(n):
		oz = list(map(lambda x: int(x), input().strip().split()))
		square.append(oz)
	print(f"area of the biggest square: {biggest_square(square)}")


# ~ 1 1 0 0 1 1 1 0
# ~ 0 1 0 1 0 0 0 1
# ~ 1 1 0 1 1 1 1 0
# ~ 1 1 1 1 1 0 1 1
# ~ 1 1 1 1 0 0 1 0


# ~ 1 1 0 1
# ~ 0 1 1 0
# ~ 0 1 1 0
# ~ 0 0 1 0


# ~ 1 1 0 1
# ~ 0 1 1 1
# ~ 0 1 1 1
# ~ 0 0 1 0
