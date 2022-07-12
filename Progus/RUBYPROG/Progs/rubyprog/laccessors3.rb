class Thing

	attr_accessor :name, :description
	#attr_writer :name,:description
	attr_accessor :value,:id,:owner
end

thing = Thing.new
thing.name = "The thing"
thing.description = " is so soft"
thing.value = 5
thing.id = "556f"
thing.owner = "me"

puts "#{thing.name}#{thing.description}"
puts "It's value is $#{thing.value}"
puts "Id = #{thing.id}"
puts "Owner: #{thing.owner}"
gets