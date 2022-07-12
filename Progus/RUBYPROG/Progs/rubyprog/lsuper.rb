

class Thing

	def initialize(aName, aDescription)
		@name = aName
		@description = aDescription
		puts "Thing.initialize:: #{self.inspect}\n\n"
	end
	
	def aMethod(aNewName)
		@name = aNewName
		puts "Thing.aMethod:: #{self.inspect}\n\n"
	end
	
end

class Thing2 < Thing
	
	def initialize(aName, aDescription)
		super
		@fullDescription = "Name: #{@name}, Description: #{@description}"
		puts "Thing2.initialize:: #{self.inspect}\n\n"
	end
	
	def aMethod(aNewName, aNewDescription)
		super(aNewName)
		@description = aNewDescription
		puts "Thing2.aMethod:: #{self.inspect}\n\n"
	end
	
end

class Thing3 < Thing2

	def initialize(aName, aDescription, aValue)
		super(aName, aDescription)
		@value = aValue
		puts "Thing3.initialize:: #{self.inspect}\n\n"
		puts "\n****#{self}****\n"
	end
	
	def aMethod(aNewName, aNewDescription, aNewValue)
		super(aNewName, aNewDescription)
		@value = aNewValue
		puts "Thing3.aMethod:: #{self.inspect}\n\n"
	end
	
end

class Thing4 < Thing3
	
	def aMethod
		puts "Thing4.aMethod:: #{self.inspect}\n\n"
	end
	
end

class Thing5 < Thing4

end

#some function or method

#-----Thing Object-----
def test1
	puts "==================test 1=================="
	t1 = Thing.new("A thing", "Inside the test1 method")
	t1.aMethod("A new thing")
end

#-----Thing2 Object-----
def test2
	puts "==================test 2=================="
	t2 = Thing2.new("A thing2", "Inside the test2 method")
	t2.aMethod("A new thing2", "A new description to thing2")
end

#-----Thing3 Object-----
def test3
	puts "==================test 3=================="
	t3 = Thing3.new("A thing3", "Inside the test3 method", 3)
	t3.aMethod("A new thing3", "A new description to thing3", 30)
end

#-----Thing4 Object-----
def test4
	puts "==================test 4=================="
	t4 = Thing4.new("A thing4", "Inside the test4 mehod", 4)
	t4.aMethod
end

#-----Thing5 Object-----
def test5
	puts "==================test 5=================="
	t5 = Thing5.new("A thing5", "Inside the test5 method", 5)
	t5.aMethod
end

#'main'---Loop
ans = ''
puts "Run Test 1, 2, 3, 4, 5?\nWrite a number or 'q' to quite. Then press [ENTER]\n\n"

until ans == 'q' do
	puts "Enter 1, 2, 3, 4, 5 or 'q'?"
	print ">"
	ans = gets[0].chr().downcase()
	case ans
		when '1' then test1()
		when '2' then test2()
		when '3' then test3()
		when '4' then test4()
		when '5' then test5()
	end
end
puts "======================================================"
puts "======================================================"
tempt = Thing5.new("Mash", "Ultime of Mashiur Rahman", "11")

