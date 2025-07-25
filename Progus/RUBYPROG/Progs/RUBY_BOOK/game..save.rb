require 'yaml'

#Thing
class Thing
	attr_accessor(:name)
	
	def initialize(aName)
		@name = aName
	end
	
	def describe
		print("#{self.name}")
	end
end

#Treasure
class Treasure < Thing
	attr_accessor(:value)
	
	def initialize(aName, aValue)
		super(aName)
		@value = aValue
	end
	
	def describe
		super
		print(" (worth #{@value} groats).")
	end
end

#Room
class Room < Thing
	#TODO: Add Room-specific behaviour
	attr_accessor(:treasures)
	
	#@treasures will be an array
	def initialize(aName, someTreasures)
		super("#{aName}")
		@treasures = someTreasures
	end
	
	def describe
		super
		if(@treasures.length == 0)
			print(" which is empty.")
		elsif(@treasures.length == 1)
			print(" which contains only a ")
			@treasures[0].describe()
		else
			print(" which contains: ")
			@treasures.each{
				|a_treasure|
				puts()
				print("     ")
				a_treasure.describe()
			}
		end
	end
end

#Map
class Map
	#@rooms will be an array -an ordered list
	# of Room objects
	def initialize(someRooms)
		@rooms = someRooms
	end
	
	#The to_s method iterates over all the Room objects in @rooms
	# and prints information on each.
	def describe
		if @rooms.empty? then puts("The Map is empty.")
		else 
			puts("This is a map containing these locations: ")
			puts()
			i = 1
			@rooms.each do
				|a_room|
				print("#{i}. ")
				a_room.describe()
				puts()
				i+=1
			end
		end
	end
end

#First create a few objects
#	i) Treasures
t1 = Treasure.new("A Sword", 800)
t2 = Treasure.new("A Dragon Horde", 550)
t3 = Treasure.new("An Elvish Ring", 3000)

#  ii) Rooms
room1 = Room.new("Crystal Grotto", [])
room2 = Room.new("Dark Cave", [t1])
room3 = Room.new("Forest Glade", [t2, t3])

# iii) a Map - which is an array containing the Rooms just created
mymap = Map.new([room1, room2, room3])

File.open('game.yml', 'w'){
	|f|
	$a = YAML.dump(mymap, f)
}

puts("------------------------")
puts mymap.to_yaml
puts("------------------------")

mymap = Map.new([])				# empty the map after saving
puts("Game saved. \nBefore reloading... ")
mymap.describe()

File.open('game.yml'){
	|f|
	mymap = YAML.load(f)
}

puts("\n\nAfter reloading... ")
mymap.describe()
	

