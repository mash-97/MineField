require 'pp'

class Array
	def cutInPieces(piece_length = 1)
		return [] if piece_length <= 0
		length = self.length
		x = 0
		y = piece_length
		pieces = []
		while(y<=length) do
			pieces << self[x...y]
			x = y
			y += piece_length
		end
		if(length+piece_length > y) then pieces << self[x...length] end
		return pieces
	end
end

class Targets_Hunting

	attr_accessor :groups, :N, :TI

	def initialize(total_players, group_names, players)
		@N = Math::sqrt(total_players).round
		@TI = Math::sqrt(@N).round
		@groups = []
		make_groups(group_names: group_names, players: players)
	end
		
	def make_groups(hash)
		return nil if hash.class != Hash
		return nil if not (hash.keys.include?(:players) && hash.keys.include?(:group_names))
		
		if (hash[:group_names].length < @N) || (hash[:players].length < @N*@N) then return nil end
		hash[:players] = hash[:players].shuffle!.cutInPieces(@N)
		
		@N.times{|id|
			group = Group.new(hash[:group_names][id], id+1)
			hash[:players][id].shuffle!
			group.setPlayers(hash[:players][id])
			@groups << group
		}
		@groups
	end
	
	def disp
		@groups.each{|group|
			puts("Group Name: #{group.name} :: ID: #{group.id}")
			group.showPlayers()
		}
	end
			
end

class Integer
	def divisors
		divisors = []
		(1..(Math.sqrt(self)).to_i).each{|i| divisors << [i, self/i] if self % i == 0}
		return divisors
	end
end

biggest = {
	:number => 0,
	:length => 0,
	:divs   => []
}
(1..100).each{|x| 
	puts("For #{x}:")
	divs = x.divisors
	if(biggest[:length] < divs.length) then
		biggest[:number] = x
		biggest[:length] = divs.length
		biggest[:divs] = divs
	end
	p divs
	puts
}


puts
puts 
puts("Number with maximum divisors: #{biggest[:number]}, length: #{biggest[:length]}")
p(biggest[:divs])
