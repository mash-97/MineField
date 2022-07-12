$dir_size = 0
$files_size = []

def processFiles(aDir)
	total_size_in_bytes = 0
	Dir.foreach(aDir){
		|f|
		file_path = "#{aDir}//#{f}"
		
		if(File.directory?(file_path)==true) then
			if(f!='.' and f!='..') then
				fsize = processFiles(file_path)
				puts("<DIR> ---> #{file_path} contains [#{fsize/1024}] KB")
				$files_size << fsize
			end
		else
			fsize = File.size(file_path)
			total_size_in_bytes += fsize
		end
	}
	$dir_size += total_size_in_bytes
	return total_size_in_bytes
end

dir = gets().chomp()

if(File.directory?(dir)==false) then puts("Wrong Dirctory!")
else
	processFiles(dir)
	printf("Size of #{dir} and subdirectories is #{$dir_size}bytes, #{$dir_size/1024}KB, %0.2fMB.\n\n", $dir_size/(1024**2))
	puts("Unordered Files size array:")
	for i in 0...$files_size.length do print("#{$files_size[i]}    ") end
	puts
	puts
	puts("Unordered without zeroes:")
	$files_size.delete(0)
	for i in 0...$files_size.length do print("#{$files_size[i]}    ") end
	puts
	puts
	puts("Ordered low to high:")
	$files_size.sort!
	for i in 0...$files_size.length do print("#{$files_size[i]}	   ") end
	puts("\n")
	puts("Ordered high to low:")
	$files_size.reverse!
	for i in 0...$files_size.length do print("#{$files_size[i]}	   ") end
	puts
	puts
end
gets()
	
