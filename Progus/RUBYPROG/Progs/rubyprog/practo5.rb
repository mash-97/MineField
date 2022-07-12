#Class Method vs Instance Method.

class Adder
	attr_accessor :a, :b
	def initialize(a,b)
		@a = a
		@b = b
	end
	
	def Adder.add(a,b)
		a+b
	end
	
	def add
		@a+@b
	end
	
end

a = Adder.new(6,7)
puts "a.add = #{a.add}"
puts "add(7,8) = #{Adder.add(7,8)}"
a.a = 9
a.b = 10
puts("a.add = #{a.add}")
gets