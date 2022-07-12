require("fileutils")

def copyFiles(source_directory, target_directory)

		Dir.foreach(source_directory){
			|file|
			
			source_file_path = "#{source_directory}//#{file}"
			target_file_path = "#{target_directory}//#{file}"
			puts source_file_path
			puts target_file_path
			gets()
			
			if(File.file?(source_file_path)==true && File.exist?(target_file_path)==false) 
				ret = FileUtils.cp(source_file_path, target_directory)
				puts("In first condition: return value = #{ret}")
				
			elsif(File.directory?(source_file_path))

				if(File.exist?(target_file_path)==true && File.directory?(target_file_path)==true && Dir.empty?(source_file_path)==false) then
					puts("E 1")
					#copyFiles(source_file_path, target_file_path)
					#if(file != '.' and file != '..') then
					if(not Dir.empty?(source_file_path)) then
						copyFiles(source_file_path, target_file_path)
					end
					
				else
					puts("E 2")
					if(not File.exist?(target_file_path)) then FileUtils.mkdir(target_file_path) end
					if(not Dir.empty?(source_file_path)) then
					#if(file != '.' and file != '..') then
						copyFiles(source_file_path, target_file_path)
					end
				end
			end
		}

end
		



print("Enter the directory name from where all the files will be copied: ")
source_directory = gets().chomp()

if(not File.exist?(source_directory)) then
	puts("Directory name as #{source_directory} not found.")

else
	print("Enter the directory name to where all the files will be copied: ")
	target_directory = gets().chomp()
	
	t_e = true
	if(not File.exist?(target_directory)) then 
		puts("The directory '#{target_directory}' doesn't exist.")
		print("Do you want to create this directory?(y/n):: ")
		
		ans = gets().chomp()
		if(ans[0].downcase() == 'y') then
			FileUtils.mkdir(target_directory)
			t_e = true
		else t_e = false end
	end
	
	if(t_e==true) then
		copyFiles(source_directory, target_directory)
	end
end

gets()
puts("END")
					
			
