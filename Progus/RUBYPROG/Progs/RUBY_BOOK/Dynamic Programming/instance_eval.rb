class MyClass
	def initialize
		@aVar = "Hello World"
	end
end

ob = MyClass.new
p(ob.instance_eval {@aVar})		#=> "Hello World"
p(ob.instance_eval("@aVar"))		#=> "Hello World"
# p(ob.eval("@aVar"))			#=> error: eval is a private method

#class Object
	public :eval				#=> Try commenting this out!
#end

p(ob.eval("@aVar"))				#=> "Hello World"
