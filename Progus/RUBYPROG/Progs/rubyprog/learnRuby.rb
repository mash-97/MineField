class Dog
	def set_name(aName)
		@name = aName
	end
	
	def get_name
		return @name
	end
	
	def talk
		return "BEOW"
	end
end

myDog = Dog.new
myDog.set_name('Nens')
puts "my dogs name: #{myDog.get_name}"
puts (myDog.talk)