doc1 = <<NOTE
You may want to print this out for ease of comparison with the output.
NOTE
puts doc1
#Some arrays to play about with.
array1 = [1,1,2,2,3,3]
array2 = [1,2,3,4,5,6,7,8,9]
array3 = ['h', 'e', 'l', 'l', 'o', ' ', nil, 'w', 'o', 'r', 'l', 'd']


#an array containing several more levels of 'sub arrays'

multiarray = [
				['one', 'two', 'three', 'four'],
				[1,2,3,4],
				["l", ["wandered", "lonely"], 'as', ["a", "cloud"]
				]
			]

#Copies of array1 and array3 so that we can restore their original state after
#changing their contents!

copy_of_array1 = array1.clone
copy_of_array3 = array3.clone			


#An utility method to print line numbers before inspecting values.
#To make it easier to match output with the numbered tests below.

@linenum = 0

def wr(exp)
	@linenum += 1
	print("(\##{@linenum})")
	p(exp)
end


#Testing various Array methods.
#Compare output with the numbered tests.
wr(array1 & array2)				#1
wr(array1 + array2)				#2
wr(array1 - array2)				#3
wr(array2 - array1)				#4
wr(array1 << array2)			#5			#this modifies array1
wr(array1)						#6
array1.clear					#This modifies the arrray
wr(array1)						#7
array1 = copy_of_array1
wr(array1)						#8
wr(array3.compact)				#9
array3.delete('l')				#This modifies the array
wr(array3)						#10
array3.delete_at(2)
wr(array3)						#11
array3 = copy_of_array3
wr(array3.length)				#12
wr(array3.reverse)				#13
array3.compact!					#Remove nils
wr(array3)						#14
wr(array3.sort)					#15 		#this doesn't work if array contains nil!
wr(multiarray.flatten)			#16
wr(multiarray)					#17
wr(multiarray.reverse)			#18
wr(multiarray.length)			#19

gets