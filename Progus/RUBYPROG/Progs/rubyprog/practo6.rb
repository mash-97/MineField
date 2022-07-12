One_light_years = 3*100000000*60*60*24*365
class Multiverse
	def initialize(name_of_the_universe, size_inMeters, distance_from_earth_inMeters)
		@name = name_of_the_universe
		@size = size_inMeters.to_f
		@distance = distance_from_earth_inMeters.to_f
	end
	
	def lightYears_to_meters(lightYear)
		return (One_light_years*lightYear).to_f
	end
	
	def displayDetailsOfTheUniverse
		puts("Name: #{@name}")
		puts("Size: #{meters_to_lightYears(@size)} light years")
		puts("Distance: #{meters_to_lightYears(@distance)} light years")
		puts One_light_years
	end
end
def meters_to_lightYears(meter)
	return ((1.0/One_light_years))*meter
end
universe = Multiverse.new("Milky Way", 59999*One_light_years, 7999777*One_light_years)
universe.displayDetailsOfTheUniverse

gets
		