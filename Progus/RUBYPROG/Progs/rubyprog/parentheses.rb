#### parentheses .rb ####
#Parentheses avoid ambiguity.

greet = "Hello"
name = "Fred"

def greet(g)
	return("Good Morning " << g)+"!"
end

def name()
	return("Mary")
end

def sayHi (aName)
	return("Hi, #{aName}")
end

puts(greet)
puts greet(greet)
puts(sayHi(name))
puts(sayHi(name()))
puts
puts
puts greet(greet)
gets