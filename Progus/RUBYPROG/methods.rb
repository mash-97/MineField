
################################################################################################################################################################
################################################################################################################################################################
#															       METHODS                                                                                     #
################################################################################################################################################################
################################################################################################################################################################

def wClass(aClassStr)
	f = File.open("/home/mash/Progus/RUBYPROG/classes.rb", "a")
	if(f==nil) then puts("File isn't opened!")
	else
		f.puts(aClassStr)
		f.close
	end
end

################################################################ Finding Type File ################################################################################
$total_files = 0
$total_single_files = Hash.new{|k,v| v = 0}
$types = []
def findFile(aFile)
	Dir.foreach(aFile){
		|file|
		file_path = aFile+"/"+file
		ex = File.extname(file)
		if(file!='.' and file!='..') then
			if(File.file?(file_path)==true) then 
				#if(ex=='.mp4' || ex=='.av' || ex=='.mkv' || ex=='.3gp' || ex=='.webm') then
				if($types.include?(ex)==true) then
					puts("#{ex} File: #{file}")
					puts("file_path: #{file_path}")
					puts
					$total_files +=1
					$total_single_files[ex] += 1
				end
			elsif(File.ftype(file_path)=='directory') then 
				findFile(file_path)
			end
		end
	}
end

def findTypes
	print("Types: ")
	$types = gets.chomp
	$types = $types.split

	print("Directory name: ")
	f = gets.chomp
	findFile(f)

	puts("There are total #{$total_files} #{$types} files in this directory")
	$total_single_files.each{|k,v| puts("#{k}: #{v}")}
	gets
end
###############################################################################################################################################################
def download_files()
	puts("=============> Download Files <===============")
	`gnome-terminal --window --active -- ruby #{File.dirname(__FILE__) + '/Mash_Files/' + 'Youtube_dl/youtube_dl.rb'}`
end
def download_files_from(path)
	puts("=============> Download Files <===============")
	`gnome-terminal --window --active -- ruby #{path}`
end


def workifyDir(dir_path, &block)
	return false if not Dir.exists?(dir_path)
	Dir.foreach(dir_path) do |file_name|
		file_path = File.join(dir_path, file_name)
		
		next if file_name == "." or file_name == ".."
		
		workifyDir(file_path, &block) if File.directory?(file_path) 
		
		yield(file_path) if File.file?(file_path)
	end
end
