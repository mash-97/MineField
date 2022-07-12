require('yaml')

class CD
	def initialize(theArtist, theName, theNumTracks)
		@aritst = theArtist
		@name = theName
		@numtracks = theNumTracks
	end
end

array_1 = [['The Groovsters', 'Groovy Tunes', 12],
		   ['Dolly Parton', 'Greatest Hits', 38]]

array_2 = [CD.new(array_1[0][0], array_1[0][1], array_1[0][2]), CD.new(array_1[1][0], array_1[1][1], array_1[1][2])]


puts(array_1.to_yaml)
puts(array_2.to_yaml)

y(array_1)
y(array_2)
