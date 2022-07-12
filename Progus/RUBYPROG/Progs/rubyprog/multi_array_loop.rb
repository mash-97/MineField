#Creating an array with two sub-arrays.  I.E: 2 'rows' each with 4 elements.

multiarray = [['one', 'two', 'three', 'four'],
			  [1,2,3,4]
			 ]
			 
#Iterate over the elements ('rows') of multiarray.

puts("for i in..(multi-dimensional array)")
for i in multiarray
	puts(i.inspect)
end

puts("\nfor a,b,c,d in..(multi-dimensional array)")
for a,b,c,d in multiarray
	print("a = #{a}, b = #{b}, c = #{c}, d = #{d}\n")
end

#Instead of a for loop you could use this block iterator.
puts("\nBlock iterator #1..")
multiarray.each do |a,b,c,d|
	print("a = #{a}, b = #{b}, c = #{c}, d = #{d}\n")
end

#This block iterator uses the alternative {} delimiters.
puts("\Block iterator #2...")
multiarray.each{
	|a,b,c,d|
	print("a = #{a}, b = #{b}, c = #{c}, d = #{d}\n")
}

gets