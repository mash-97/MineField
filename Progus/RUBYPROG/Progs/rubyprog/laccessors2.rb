class Thing
	
	def initialize(aName, aDescription)
		@name = aName
		@description = aDescription
	end
	attr_accessor(:name, :description)
	
end

class Treasure < Thing
	
	def initialize(aName, aDescription)
		super(aName, aDescription)
	end
	
	attr_accessor :value
	
end

#program starts from here

o1 = Treasure.new("Mash", "Ultima of Mashiur Rahman")
o1.value = 5
puts "Name: #{o1.name}\nDescription: #{o1.description}\nValue: #{o1.value}"

puts "Inspecting o1:",o1.inspect

o1.name = "Gash"
o1.description = "Ultima of Zachbell"
o1.value = 6
puts "Name: #{o1.name}\nDescription: #{o1.description}\nValue: #{o1.value}"
puts "Inspecting o1:",o1.inspect
gets