#Illustrates how to creating descendant objects
#Reading and writing attribute
#Object (instance) variables
#Class variables
#Thing Class
class Thing
	@@num_things = 0 #Class @@ variables, to count the total created objects
	attr_reader :name, :description
	attr_writer :description
	def initialize(aName, aDescription)
		@name = aName
		@description = aDescription
		@@num_things += 1 #Increamenting @@num_things
	end
	def to_s # override default to_s method
		return "(Thing.to_s):: The #{@name} Thing is #{@description}"
	end
	def show_classvars
		return "There are #{@@num_things} Thing Objects in this game"
	end
end
#Room Class
class Room < Thing #Room class descends from the Thing class
	#some methods to be written
end
#Treasure Class
class Treasure < Thing
	attr_accessor :value
	def initialize(aName, aDescription, aValue)
		super(aName, aDescription)
		@name = aName
		@description = aDescription
		@value = aValue
	end
end
#Map Class
class Map
	#@rooms will be an array- a ordered list of Room objects
	def initialize(someRooms)
		@rooms = someRooms
	end
	#The to_s method iterates over all the Room Objects in @rooms and prints information on each.
	def to_s
		@rooms.each{|a_room| puts a_room}
	end
end
#Program starts from here
#First we are going to create some objects
#    i)Treasures
treasure1 = Treasure.new("Sword", "An elvish weapon forged by gold", 800)
treasure2 = Treasure.new("Dragon Horde", "A huge pile of Jewels", 550)
#   ii)Rooms
room1 = Room.new("Crystal Grotto", "A glittery cavern")
room2 = Room.new("Dark Cave", "A gloomy hole in rocks")
room3 = Room.new("Forest Glad", "A verdant clearing filled with shimmering light")
#  iii)Map   
mymap = Map.new([room1, room2, room3])
##Now lets take a look of what we have got
puts "\nLet's inspect the treasures....."
puts "\n(treasure1):: #{treasure1.inspect}"
puts "\n(treasure2):: #{treasure2.inspect}"
puts "\n\nLet's try out all the Thing.to_s method"
puts "\n(treasure1.to_s):: #{treasure1.to_s}"
puts "\n(treasure2.to_s):: #{treasure2.to_s}"
puts "\n\nNow let's see how our attributes work"
puts "\nWe will evalute this:"
puts 'Treasure:: name: , description: , value: '
puts "\ntreasure1:: name: #{treasure1.name}, description: #{treasure1.description}, value: #{treasure1.value}"
puts "\ntreasure2:: name: #{treasure2.name}, description: #{treasure2.description}, value: #{treasure2.value}"
puts "\n\nNow we will assign 100 into treasure1.value and alter treasure1.description: "
treasure1.value = 100
treasure1.description << " now it's tarnished"
puts "\ntreasure1:(after changing): name: #{treasure1.name}, description: #{treasure1.description}, value: #{treasure1.value}"
puts "\n\nLet's see one of the Room Object"
puts "\n(room1.inspect): #{room1.inspect}"
puts "\n(room2.inspect): #{room2.inspect}"
puts "\n(room3.inspect): #{room3.inspect}"
puts "***************************"
puts "***************************"
puts "\n\nNow look at the map"
puts "\nmymap = #{mymap.to_s}"
puts "***************************"
puts "***************************"
puts "\n\nFinally we will see how many Thing Objects are there"
puts ("treasure1:: #{treasure1.show_classvars}")
puts ("treasure2:: #{treasure2.show_classvars}")
gets

