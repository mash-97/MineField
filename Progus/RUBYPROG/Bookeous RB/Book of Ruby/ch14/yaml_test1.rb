# The Book of Ruby - http://www.sapphiresteel.com

require 'yaml'

class Treasure
	def initialize( aName, aValue )
		@name = aName
		@value = aValue
	end
end


# y is a shortcut to print out object in yaml format
puts( ['Bert', 'Fred', 'Mary'] .to_yaml)
puts( { 'fruit' => 'banana', :vegetable => 'cabbage', 'number' => 3 }.to_yaml )
t = Treasure.new( 'magic lamp', 500 )
puts( t.to_yaml )
