module MyModule
	GOODMOD = "Good!"
	BADMOOD = "Bad!"
	def greet(zeroOrOne)
		puts("I'm in #{GOODMOD}")if(zeroOrOne==1)
		puts("I'm in #{BADMOOD}")if(zeroOrOne==0)
	end
	
	def self.greet
		puts("YO! you are in #{GOODMOD} but he looks #{BADMOOD}")
	end
end

puts("MyModule::GOODMOD")
puts(MyModule::GOODMOD)

puts("MyModule::greet")
puts(MyModule::greet)

include MyModule
puts("greet")
greet(1)
gets