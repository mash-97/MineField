module MyModule
	GOODMOOD = "happy"
	BADMOOD = "grumpy"
	def greet
		return "I'm #{GOODMOOD}. How are you?"
	end
	
	def MyModule.greet
		return "I'm #{BADMOOD}. How are you?"
	end
	
	def sayHi
		return MyModule.greet
	end
end

def sing
	puts("Tra-la-la-la")
end
puts("module loaded")
sing()
