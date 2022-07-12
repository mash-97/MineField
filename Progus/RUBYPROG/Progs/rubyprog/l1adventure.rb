class Thing

	def initialize(aName, aDescription)
		@name = aName
		@description = aDescription
	end

	def get_name
		return @name
	end

	def set_name(aName)
		@name = aName
	end

	def get_description
		return @description
	end

	def set_description(aDescription)
		@description = aDescription
	end

end


class Treasure < Thing #Treasure Descends From Thing

	def initialize(aName, aDescription, aValue)
		super(aName, aDescription)
		@value = aValue
	end

	def get_value
		return @value
	end

	def set_value(aValue)
		@value = aValue
	end
end


#This is where our program starts
treasure = Treasure.new("Sowrd", "An elvish weapon, that can cut somewhat!", 400)
puts
print "Inspecting the treasure object:",treasure.inspect
puts
puts "Inside the treasure object:"

print "Name = ",treasure.get_name
puts
print "Description = ",treasure.get_description
puts
print ("Value = "),treasure.get_value,"\n"

#setting new value, name and description
treasure.set_name("Mahim")
treasure.set_description("Very Naughty Boy Himself")
treasure.set_value(951)

#showing treasure object as newsome
puts
print"Inspecting the treasure object again: ", treasure.inspect
puts
puts "Inside the treasure object:"
print "Name = ",treasure.get_name,"\n"
print "Description = ",treasure.get_description,"\n"
print "Value = ",treasure.get_value,"\n"
gets