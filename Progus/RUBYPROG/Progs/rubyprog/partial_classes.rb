class A
	def initialize(aName)
		@name = aName
	end
	def a
		puts self.inspect
		puts( "a" )
	end
end

class B < A
	def ba1
		puts( "ba1" )
	end
end

class A
	def b
		puts( "b" )
	end
end

class B < A
	def ba2
		puts( "ba2" )
	end
end


class Array
	def gribbit
		puts( "gribbit" )
	end
end

ob = B.new("")
ob.a
ob.b
ob.ba1
ob.ba2
[1,2,3].gribbit
puts"*********"
cd = A.new("AAA")
cd.a