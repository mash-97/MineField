require("yaml")

$cd_array = Array.new
$file_name = "cd.yml"

class CD
	def initialize(array)
		@name 		= array[0]
		@artist     = array[1]
		@num_tracks = array[2]
	end
	
	def getDetails()
		return [@name, @artist, @num_tracks]
	end
end

class PopCD < CD
	def initialize(array)
		super(array)
		@genre = array[3]
	end
	
	def getDetails()
		return(super << @genre)
	end
end

class ClassicalCD
	def initialize(array)
		super(array)
		@conductor = array[3]
		@composer  = array[4]
	end
	
	def getDetails()
		return(super << @conductor << @composer)
	end
end

def otherCD()
	print("Enter CD name: ")
	cd_name = gets().chomp()
	print("Enter artist's name: ")
	artist_name = gets().chomp()
	print("Enter number of tracks: ")
	num_tracks = gets().chomp()
	
	return([cd_name, artist_name, num_tracks])
end

def classicCD()
	cd_info = otherCD()
	
	print("Enter conductor's name: ")
	conductor_name = gets().chomp()
	print("Enter composer's name: ")
	composer_name = gets().chomp()
	
	cd_info << conductor_name << composer_name
	
	return(cd_info)
end

def popCD()
	cd_info = otherCD()
	
	print("Enter genre of music: ")
	genre = gets().chomp()
	
	cd_info << genre
	return(cd_info)
end

def addCD(cd_obj)
	$cd_array << cd_obj
end

def saveDB()
	File.open($file_name, 'w'){|f|
		f.write($cd_array.to_yaml)
	}
end

def loadDB()
	File.open($file_name){|f|
		$cd_array = YAML::load(f)
	}
end

def showData()
	puts($cd_array.to_yaml)
end

if(File.exist?($file_name)) then
	loadDB()
	showData()
else puts("File doesn't exist!") end

ans = ''

until ans=='q' do
	print("Create (P)op CD, (C)lassic CD or (O)ther CD- (S)ave or (Q)uite:: ")
	ans = gets[0].chr().downcase()
	case ans
		when 'o' then addCD(CD.new(otherCD()))
		when 'p' then addCD(PopCD.new(popCD()))
		when 'c' then addCD(ClassicalCD.new(classicCD()))
		when 's' then saveDB()
	end
	showData()
end

puts("")
gets()
puts("END")
