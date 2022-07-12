class Array
	def p
		puts self.inspect
	end
	def gribit
		puts "GRIBIT"
	end
	def sum
		@a = 0
		self.each{|num| @a += num}
		return @a
	end
end

a = Array.new
a.p
a.gribit


puts([1,2,3,4, 9999].sum)
gets