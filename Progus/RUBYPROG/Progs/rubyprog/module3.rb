module MyModule
	GOODMOOD = 'Happy'
	BADMOOD  = "Grumpy"
	def greet
		return "I'm #{GOODMOOD}. How are you?"
	end
	
	def MyModule.greet
		return "I'm #{BADMOOD}. How are you?"
	end
end

class MyClass
	include MyModule
	def sayHi
		puts(greet)
	end
end

ob = MyClass.new
ob.sayHi
puts(greet)

gets