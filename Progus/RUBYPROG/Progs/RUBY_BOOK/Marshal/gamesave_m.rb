#Thing Class
class Thing
	attr_accessor(:name)
	
	def initialize(aName)
		@name = aName
	end
	
	def describe
		print("#{self.name}")
	end
end

#Treasure Class
class Treasure < Thing
	attr_accessor(:value)
	def initialize(aName, aValue)
		super(aName)
		@value = aValue
	end
	
	def describe
		super
		print(" (worth #{@value} groats). ")
	end
end

#Room Class
class Room < Thing
	#TODO: Add Room-specific behaviour
	attr_accessor(:treasures)
	
	#@treasures will be an array
	def initialize(aName, someTreasures)
		super(aName)
		@treasures = someTreasures
	end
	
	def describe
		super
		if @treasures.length == 0
			puts(" which is empty.")
		else
			puts(" which contains: ")
			@treasures.each{
				|a_treasure|
				print("    ")
				a_treasure.describe
				puts
			}
		end
	end
end

#Map Class
class Map
	#@rooms will be an array - an ordered list
	#of Room objects
	def initialize(someRooms)
		@rooms = someRooms
	end
	
	#The to_s method iterates over all the Room objects in @rooms
	#and prints information on each.
	def describe
		puts("This is a map containing these locations:")
		@rooms.each{
			|a_room|
			a_room.describe
		}
	end
end

#First create a few objects
#   i) Treasures
t1 = Treasure.new("A Sword", 800)
t2 = Treasure.new("A Dragon Horde", 550)
t3 = Treasure.new("An Elvish Ring", 3000)

#  ii) Rooms
room1 = Room.new("Crystal Grotto", [])
room2 = Room.new("Dark Cave", [t1])
room3 = Room.new("Forest Glade", [t2, t3])

# iii) a Map - which is an array containing the Rooms just created
mymap = Map.new([room1, room2, room3])

File.open('game.sav', 'w'){
	|f|
	Marshal.dump(mymap, f)
}

mymap = Map.new([])			#empty the map after saving
puts("Game saved. \nBefore reloading... ")
mymap.describe

File.open('game.sav'){
	|f|
	mymap = Marshal.load(f)
}

puts("\n\nAfter reloading...")
mymap.describe
