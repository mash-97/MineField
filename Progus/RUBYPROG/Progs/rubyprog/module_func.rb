module MyModule
	def sayHi
		return "Hi!"
	end
	
	def sayGoodbye
		return "Goodbye"
	end
	
	module_function(:sayHi)
end
class MyClass
	include MyModule
	def speak
		puts(sayHi)
		puts(sayGoodbye)
	end
end

ob = MyClass.new
ob.speak
puts(MyModule.sayHi)
gets