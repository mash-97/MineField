
#################################################################################################################################################################
#															Modules  Reserto		               	            								            	#
#################################################################################################################################################################

module Reserton
	require 'fileutils'
	
	class Reserto
		attr_accessor :name
		def initialize(researchName)
			@name = researchName
		end
		
		def createReserto
			
			file_path = "./#{@name}"
			if(Dir.exist?(file_path)==false) then FileUtils.mkdir(file_path) end
			#Essential Directories...
				if(Dir.exist?(file_path+"/Sub_Problems")==false) then FileUtils.mkdir(file_path+"/Sub_Problems") end
				if(Dir.exist?(file_path+"/Documents")==false) then FileUtils.mkdir(file_path+"/Documents") end
				if(Dir.exist?(file_path+"/Programs")==false) then FileUtils.mkdir(file_path+"/Programs") end
				if(Dir.exist?(file_path+"/Sources")==false) then 
					FileUtils.mkdir(file_path+"/Sources") 
					FileUtils.mkdir(file_path+"/Sources/PDFs")
					FileUtils.mkdir(file_path+"/Sources/Web_Pages")
					FileUtils.mkdir(file_path+"/Sources/Pictures")
				end
				if(Dir.exist?(file_path+"/Decisions")==false) then FileUtils.mkdir(file_path+"/Decisions") end
				
				
			#Essential Files...
				File.new(file_path+"/Conclusions.txt", 'w')
				File.new(file_path+"/Objectives.txt", 'w')
				File.new(file_path+"/Problem_Description.txt", 'w')
			return "Reserto Files Created."
		end

	end
		
	class String
		include Reserton
		def creaReserto								#creates a new reserto regard to the self
			reserto_object = Reserto.new(self)
			reserto_object.createReserto()
		end
	end
end


