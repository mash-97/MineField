########## new.rb ###########
class MyClass
	def initialize(aStr)
		@aVar = aStr
	end
	
	def MyClass.new(aStr)		#returns a string object!
		super
		@aNewVar = aStr.swapcase
	end
end
ab = MyClass.new 
ob = MyClass.new("Hello World")
puts(ob)
puts(ob.class)
p ob
p ab
gets