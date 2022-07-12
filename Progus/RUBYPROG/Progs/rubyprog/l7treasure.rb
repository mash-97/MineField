class Thing
	def set_name(aName)
		@name = aName
	end
	
	def get_name
		return @name
	end
end

class Treasure
	def initialize(aName, aDescription)
		@name = aName
		@description = aDescription
	end
	
	def to_s #overriding default to_s method in main object
		return "A #{@name} is a #{@description}"
	end
end



thing = Thing.new
thing.set_name("Mashiur Rahman")
puts thing.get_name


t = Treasure.new("Sword", "A thin object, as it can rip out smooth thing")
t1 = Treasure.new("Treasure", "A thing that can be splited into many pieces")

puts t.to_s
puts t1.to_s


puts thing.inspect
puts t.inspect
puts t1.inspect
gets


