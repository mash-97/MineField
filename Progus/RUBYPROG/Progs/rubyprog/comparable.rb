class MyArray < Array
	include Comparable
	
	def <=> (anotherArray)
		self.length <=> anotherArray.length
	end
end

class Array2 < Array
	include Comparable
end

myarray1 = MyArray.new([0, 1, 2, 3])
myarray2 = MyArray.new([1,2,3,4])
myarray3 = MyArray.new([0, 1, 2, 3, 5])

array1 = Array2.new([0, 1, 2, 3])
array2 = Array2.new([1, 2, 3, 4])
array3 = Array2.new([0, 1, 2, 3, 5])



puts("\nMyArray")
p(myarray1 < myarray2)
p(myarray1 > myarray2)
p(myarray1 == myarray2)
p(myarray3 > myarray1)
p(myarray3 <=> myarray1)
p(myarray1 <=> myarray2)

puts("Array including Comparable")
p(array1 < array2)
p(array1 > array2)
p(array1 == array2)
p(array3 > array1)
p(array3 <=> array1)
p(array1 <=> array2)

gets