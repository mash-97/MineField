array =[]
counter = 0
commando = 1
puts("For end enter null")
print("Enter numbers::\n")

until commando == 0
	print("#{counter+1}>>")
	array[counter] = gets.to_i
	if(array[counter].to_i == 0)
		commando = 0
	end
	counter += 1
end
p(array)

puts
temp = 0
for i in (0...array.length)
	temp = array[i]
	if(array[i] > array[i+1])
		array[i] = array[i+1]
		array[i+1] = temp
	end
end
p array
gets