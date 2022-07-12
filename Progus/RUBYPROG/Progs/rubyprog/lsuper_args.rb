class Class1
	
	def initialize(a,b,c)
		@a = a
		@b = b
		@c = c
		puts self.inspect
	end

end

class Class2 < Class1
	
	def initialize(a, b, c, d, e, f, g)
		@a = a
		@b = b
		@c = c
		@d = d
		@e = e
		@f = f
		@g = g
		puts self.inspect
		super(d, e, f)
	end
	
end

class Class3 < Class1

	def initialize(a, b, c)
		#super ()
	end
end

class Class4 < Class1

	def initialize(a, b, c)
		super
	end
end

class Class5 < Class1
	
	def initialize(a, b, c)
	
	end
end


#main program

obj1 = Class1.new(1,2,3)
puts"Inspecting obj1:"
p(obj1)

obj2 = Class2.new(4, 5, 6, 88, 99, 77, 66)
puts"Inspecting obj2:"
p(obj2)
puts"Inspecting obj1:"
p(obj1)

obj3 = Class3.new(7,8,9)
puts"Inspecting obj3:"
p(obj3)
puts"Inspecting obj1:"
p(obj1)

obj4 = Class4.new(10,11,12)
puts"Inspecting obj4:"
p(obj4)
puts"Inspecting obj1:"
p(obj1)

obj5 = Class5.new(13,14,15)
puts"Inspecting obj5:"
p(obj5)
puts"Inspecting obj1:"
p(obj1)
gets
gets

puts"******"
temp = Class2.new(1,2,3,4,5,6,7)
