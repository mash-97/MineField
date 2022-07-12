require("fileutils")

def copyFiles(source, target)
	Dir.foreach(source){
		|f|
		source_path = source+'//'+f; #puts source_path
		target_path = target+'//'+f; #puts target_path
		
		if(File.file?(source_path)==true) then
			if(File.exist?(target_path)==true and File.file?(target_path)==true) then
				puts("The source file '#{f}' from '#{source}' directory is already existed in #{target}.\n")
				print("Do you want to replace it?(y/n):: ")
				ans = gets().chomp()
				if(ans[0].downcase=='y') then FileUtils.rm(target_path); FileUtils.cp(source_path, target) end
			else
				FileUtils.cp(source_path, target)
			end
		elsif(f!='.' and f!='..') then 
			if(File.directory?(target_path)==false) then FileUtils.mkdir(target_path) end
			copyFiles(source_path, target_path)
		end
	}
end

print("Enter the source directory: ")
source = gets().chomp()
if(File.directory?(source)==false) then puts("\nNo directory named #{source}\n")
else
	print("Enter the target directory: ")
	target = gets().chomp()
	
	continue = true
	if(File.directory?(target)==false) then
		puts("\nNo directory named #{target}\n")
		print("Do you want create directory named #{target}?(y/n):: ")
		ans = gets().chomp()
		if(ans[0].downcase=='y') then FileUtils.mkdir(target) else continue = false end
	end
	
	if(continue) then
		copyFiles(source, target)
	end
end

gets()
puts("END")
	
		


		
