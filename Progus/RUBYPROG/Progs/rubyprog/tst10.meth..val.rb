class A
	attr_reader(:var)
	attr_writer(:var)
	def initialize(aVar)
		@var = aVar
	end
	
	def show
		puts("@var = #{@var}")
	end
end

def aMethod(obA)
	obA.var = 60
	obA.var
end

ob = A.new(7)
ob.show

puts("Inside the method #{aMethod(ob)}")

ob.show
gets
	
	
	