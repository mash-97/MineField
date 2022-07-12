require("yaml")

#array for cd objects
$cd_array = Array.new

#file name for saving/loading
$file_name = 'cd_db.yml'

#ancestor generic CD class
class CD
	#initialize variables parsed from aray argument
	#(array)
	def initialize(array)
		@name      = array[0]
		@aritst    = array[1]
		@numtracks = array[2]
	end

	#return an array containing all instance variables of 
	# a CD object
	def getDetails
		return[@name, @artist, @numtracks]
	end
end

#PopCD is a 'child' class of CD
class PopCD < CD
	#Calls super to pass array, array, to parent (CD) class
	#This initializes three instance variables. This 
	#method initializes one more: @genre
	def initialize(array)
		super(array)
		@genre = array[3]
	end

	#Calls super to get array from CD class getdetails
	#method. Then adds @genre to the end of the array and
	#returns the entire 4-item array
	def getDetails
		return( super << @genre )
	end
end

#ClassicalCD is a 'child' class of CD
class ClassicalCD
	def initialize(array)
		super(array)
		@conductor = array[3]
		@composer  = array[4]
	end

	def getDetails
		return( super << @conductor << @composer )
	end
end

#Some methods to get data from the user
def otherCD

	print( "Enter CD name: " )
	cd_name = gets().chomp()
	print( "Enter artist's name: " )
	artist_name = gets().chomp()
	print( "Enter number of tracks: " )
	num_tracks = gets().chomp().to_i()
	
	return [cd_name, artist_name, num_tracks]
end

def classicCD
	cd_info = otherCD()
	
	print( "Enter conductor's name: ")
	conductor_name = gets().chomp()
	print( "Enter composer's name: ")
	composer_name = gets().chomp()
	
	cd_info << conductor_name << composer_name
	return(cd_info)
end

def popCD
	cd_info = otherCD()
	
	print( "Enter genre of music: ")
	genre = gets().chomp()

	cd_info << genre

	return(cd_info)
end

#Adds a CD object to the array variable, $cd_array
def addCD(aCD)
	$cd_array << aCD
end

#Saves data to disk in YAML format
def saveDB
	File.open($file_name, 'w'){
		|f|
		f.write($cd_array.to_yaml)
	}
end

#Loads data from disk and recreates the array of cd objects,
#$cd_array, from the data
def loadDB
	input_data = File.read($file_name)
	$cd_array = YAML::load(input_data)
end

#Prints the data form the array to screen in human-readable
#(YAML) format

def showData
	puts($cd_array.to_yaml)
end

#Start of Program
if File.exist?($file_name) then
	loadDB()
	showData()
else
	puts( "The file #{$file_name} cannot be found." )
end

#'main' loop
ans = ''

until ans == 'q' do
	puts( "Create (P)op CD (C)lassical CD, (O)ther CD - (S)ave or (Q)uit?" )
	print(">")
	ans = gets[0].chr().downcase()

	case ans
		when 'p' then addCD(PopCD.new(popCD()))
		when 'c' then addCD(ClassicalCD.new(classicCD()))
		when 'o' then addCD(CD.new(otherCD()))
		when 's' then saveDB()
	end
	showData()
end


gets()
puts("END")
	
	
	
	
	
	
	
	
	
