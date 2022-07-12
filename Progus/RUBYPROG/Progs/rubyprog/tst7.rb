class Adder2
	def initialize(a, b)
		@a = a
		@b = b
	end
	
	def add
		puts @a+@b
	end
end

class Adder3 < Adder2
	def add(c)
		@c = c
		puts @a+@b+@c
	end
end

aObject = Adder2.new(5, 6)
aObject.add

anotherObject = Adder3.new(1, 2)
anotherObject.add(3)
gets
puts("-----------------------")
anotherOne = Adder3.new(20, 10)
anotherOne.add(20)
gets