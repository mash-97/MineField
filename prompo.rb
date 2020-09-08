prompo_doc = <<prompo
		It's an approach to save basic inforamtion of relative or whatever, but with a 4 digits number defined by them
	is used. Where whenever a new prompo is entered the search related to the number as with all the number of others can be done.
	So it's interesting to playing with other's choiced number, other's favorite, But I think it will be made simple as possible as I can.
prompo

$PROMPO_FILE_PATH = File.absolute_path(__dir__)

module Prompon
	$promp_array = []
	$loaded_prompos = false
	
	class Prompo
		attr_accessor(:id, :is_saved)
		attr_accessor(:name, :address, :favorite_number, :details, :made_time)
		
		def initialize(name, address, details, favNum)
		#Name Stuff
			name = name.split.collect{|x|x = x.capitalize+' '}
			#name.to_s.chop!
			@name = name.join.chop
			
		#Address
			@address = address
		#Favorite Number
			@favorite_number = favNum
		#Details
			@details = details
		#Time - when this created
			@made_time = Time.now
			@is_saved = false
		#Fetching ID
			if(File.exist?($PROMPO_FILE_PATH+"/prompo.enu")==false) then 
				File.open($PROMPO_FILE_PATH+"/prompo.enu", 'w'){
					|f|
					Marshal.dump(1, f)
					f.close()
				}
			end
			
			@id = Marshal.load(File.open($PROMPO_FILE_PATH+"/prompo.enu"))
		end
		
		def to_yaml_properties
			["@id", "@name", "@address", "@details", "@favorite_number", "@made_time"]
		end
	end

	def savePrompo(prompoObject)
		require("yaml")

		if(prompoObject.is_saved==true) then return("This prompo already saved")  else  prompoObject.is_saved=true end
		#if(File.exist?("prompo.yml")==false) then File.open("prompo.yml", "w") end
		
		#Saving this prompo object in YAML format and in append mode
		File.open($PROMPO_FILE_PATH+"/prompo.yml", "a"){
			|f|
			YAML.dump(prompoObject, f)
		}

		#Updating prompo.enu
		File.open($PROMPO_FILE_PATH+"/prompo.enu", "w"){
			|f|
			Marshal.dump(prompoObject.id + 1, f)
			f.close()
		}
		$loaded_prompos = false
		return("A prompo is updated")
	end
	
	#To load all the prompo data in $prompo_array global array
	def loadPrompos
		require("yaml")
		$prompo_array = YAML.load_documents(File.open($PROMPO_FILE_PATH+"/prompo.yml"))
	end
	
	def showPrompos
		if not $loaded_prompos then loadPrompos(); $loaded_prompos=true  end
		
		puts Time.now
		$prompo_array.each{
			|x|
			puts x.id
			puts x.name
			#puts x.address
			#puts x.details
			puts x.favorite_number
			#puts x.made_time
			puts 
			puts 
		}
	end
	
	def displayPromposFrom(anObArray = [])
		if(anObArray.class == String) then puts(anObArray) 
		else
			anObArray.each{
				|ob|
				puts ob.id
				puts ob.name
				puts ob.address
				puts ob.details
				puts
				puts
			}
		end
	end
		
	
	def searchByNumber(aFavoriteNumber)
		if not $loaded_prompos then  loadPrompos()	end
		
		found_obs = []
		aFavoriteNumber = aFavoriteNumber.to_s
		if(aFavoriteNumber.length>4) then return("Number should be 4 digits long!!!") end
		
		$prompo_array.each{
			|ob|
			if(ob.favorite_number == aFavoriteNumber) then found_obs << ob end
		}
		
		if found_obs.empty? then return("No match found!!!") 
		else return found_obs end
	end
	
	def searchByName(aName)
		if not $loaded_prompos then loadPrompos() end
		
		found_obs = []
		
		aName.downcase!
		reg = /#{aName}/
		$prompo_array.each{
			|ob|
			if(ob.name.downcase =~ reg) then found_obs << ob end
		}
		
		if found_obs.empty? then return("No match found!!!") 
		else return found_obs end
	end
		
	
	def newPrompo
		puts("---------------New PROMPO----------------")
		print("Name: ")
		name = gets().chomp()
		print("Address: ")
		address = gets().chomp()
		print("Details: ")
		details = gets().chomp()
		number = ''
		until(number.length == 4) do
			print("Favorite number (only 4 digits):: ")
			number = gets().chomp()
		end
		
		return(Prompo.new(name, address, details, number))
	end
		
		
end
