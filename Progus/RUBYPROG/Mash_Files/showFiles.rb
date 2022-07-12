@total = 0
def showFiles(dir_name)
	Dir.foreach(dir_name){|f|
		file_name = dir_name+"/"+f
		if(!(f=='.' || f=='..')) then
				puts("File Name: #{file_name}")
				@total += 1
				
				if(File.directory?(file_name)) then 
					showFiles(file_name)
				end
		end
	}
end

def showF(dir_name)
	total = showFiles(dir_name)
	puts
	puts("Total Files: #{@total}")
end
