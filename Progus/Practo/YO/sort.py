def selection_sort(array):
	length = len(array)
	i = 0
	while(i<length-1):
		minimums_index = i
		j=i+1
		while(j<length):
			if(array[j]<array[minimums_index]):
				minimums_index = j
			j+=1
		
		temp = array[minimums_index]
		array[minimums_index] = array[i]
		array[i] = temp
		i+=1

def bubble_sort(array):
	length = len(array)
	i=length-1
	while(i>0):
		j = 0
		while(j<i):
			if(array[j]>array[j+1]):
				temp = array[j]
				array[j] = array[j+1]
				array[j+1] = temp
			j+=1
		i-=1

def insertion_sort(array):
	length = len(array)
	i=1
	while(i<length):
		j=i-1
		key = array[i]
		while(j>=0 and array[j]>key):
			array[j+1] = array[j]
			j-=1
		array[j+1] = key
		i+=1



n = int(input("n: "))
a = []
for i in range(n):
	num = int(input())
	a.append(num)

insertion_sort(a)
print(a)


