class Array
	def its_length
		counter = 0
		for i in self
			counter += 1
			self[counter-1] + "a"
		end
		return counter
	end
end

anArray = [1,2,3,"one", "two", "three"]

puts("#{anArray} has #{anArray.its_length} element(s)")
puts anArray
gets
