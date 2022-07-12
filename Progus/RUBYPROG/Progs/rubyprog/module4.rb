module MagicThing
	attr_accessor :power
end

module Treasure
	attr_accessor :owner
	attr_accessor :value
end

class Weapon
	attr_accessor :deadlines
end

class Sword < Weapon
	include Treasure
	include MagicThing
	attr_accessor :name
end

s = Sword.new
s.name = "Excalibur"
s.deadlines = "fatal"
s.value = 1000
s.owner = "Gribbit The Dragon"
s.power = "Glows when Orcs Appear"

puts(s.name)
puts(s.deadlines)
puts(s.value)
puts(s.owner)
puts(s.power)

gets