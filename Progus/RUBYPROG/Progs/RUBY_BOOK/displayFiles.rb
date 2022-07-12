#Displaying files from current directory to all subdirectories.
require("fileutils")

def displayFiles(aDir, num_space)
	l = num_space
	Dir.foreach(aDir){
		|file|
		file_path = aDir+'//'+file
		
		if(File.file?(file_path)==true) then
			for i in (1..l) do print("  ") end
			puts("#{file}")
		else
			
			if(file != '.' and file!= '..') then
				for i in (1..l) do print("  ") end
				puts("#{file}:\n")
				displayFiles(file_path, l+1)
				puts
			end
		end
		
	}
end

print("Enter the directory name:: ")
dir = gets().chomp()

if(File.directory?(dir)) then 
	puts("\n\n#{dir}::")
	displayFiles(dir, 1)
else puts("Not found!") end

gets()
puts("END")
