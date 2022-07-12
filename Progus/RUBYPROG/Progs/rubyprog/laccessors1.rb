class Thing
	
	def initialize(aName, aDescription)
		@name = aName
		@description = aDescription
	end
	
	def name 
		return @name
	end
	
	def description
		return @description
	end
	
	def name= (aName)
		@name = aName
	end
	
	def description= (aDescription)
		@description = aDescription
	end
end

t = Thing.new("The thing", "Will hurt you, legally you don't want it")
print "name: "
puts t.name

print "description: ",t.description,"\n"

t.name = "Ruby"
t.description = "One of the coolest programming language"

print "name has changed to: ",t.name,"\n"
print "and the description is \"",t.description,"\"\n"
gets