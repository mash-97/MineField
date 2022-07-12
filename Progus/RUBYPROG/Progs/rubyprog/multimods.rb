module MagicThing
	def m_power
		return @m_power
	end
	
	def m_power=(aPower)
		@m_power = aPower
	end
	
	class MagicClass
		attr_accessor(:woodfledust)
	end
end

module Treasure
	attr_accessor(:value)
	attr_accessor(:insurance_cost)
end

module MetalThing
	attr_accessor(:type_of_metal)
	include(MagicThing)
	class Attributes < MagicClass
		attr_accessor(:hardness)
		attr_accessor(:shininess)
	end
end

include(MetalThing)
class Weapon < MagicClass
	attr_accessor(:deadliness)
	attr_accessor(:power)
	class WeaponAttributes < Attributes
		attr_accessor(:nastiness)
	end
end

class Sword < Weapon
	include(Treasure)
	include(MagicThing)
	
	attr_accessor(:name)
end

s = Sword.new
s.name = "Excalibur"
s.deadliness = 10
s.power = 20
s.value = 500
s.insurance_cost = 10000
s.m_power = "incredibly magical"
s.woodfledust = "lots of it"
weapon_atts = Weapon::WeaponAttributes.new
weapon_atts.nastiness = "very nasty"
weapon_atts.hardness = "terribly hard"
weapon_atts.shininess = "like a mirror"

puts(s.name)
puts(s.deadliness)
puts(s.power)
puts(s.value)
puts(s.insurance_cost)
puts(s.m_power)
puts(s.woodfledust)
puts(weapon_atts.nastiness)
puts(weapon_atts.hardness)
puts(weapon_atts.shininess)
gets