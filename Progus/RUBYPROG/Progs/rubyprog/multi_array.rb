#Create an array with two sub-arrays i.e: 2 'rows'each with 4 elements
multiarr = [
				['one', 'two', 'three', 'four'],
				[1, 2, 3, 4]
		   ]

		   
#Iterate over the elements ('rows') of multiarr
puts("For i in..(multi-dimentional array)")
for i in multiarr
	puts(i.inspect)
	i.each{|a| p a}
end

puts("\nFor a, b, c, d in..(multi-dimentional array)")
for(a,b) in multiarr
	print("a = #{a}, b = #{b}\n")
end
gets

