class MyClass
	attr_accessor :name
	attr_accessor :number
	
	def initialize(aName, aNumber)
		@name = aName
		@number = aNumber
	end
	
	
	def ten
		return 10
	end

end

ob = MyClass.new("James Bond",  '007')
puts("Double-quoted: My name is #{ob.name} and my number is #{ob.number}")

puts("Here's a tab\ta new line\na calculation #{2*3} and a method-call #{ob.ten}")

puts("Single-quoted: My name is #{ob.name} and my number is #{ob.number}")

puts ('Here\'s a tab\ta new line\n a calculation #{2*3} and a method - call #{ob.ten}')
gets



puts %Q^This is what it's like #{ob.ten}^
puts %q!jj '' boom!
puts %q<This is a single quote #{ob.ten}>
gets