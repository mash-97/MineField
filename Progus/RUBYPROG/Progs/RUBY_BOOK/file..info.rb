$dirsize = 0

def processFiles(aDir)
	total_bytes = 0
	
	Dir.foreach(aDir){
		|f|
		mypath = aDir+"//"+f
		if File.directory?(mypath) then
		
			if f!= '.' and f!='..' then
				bytes_in_dir = processFiles(mypath)
				puts("<DIR> ---> #{mypath} contains [#{bytes_in_dir/1024}] KB")
			end
		else
			filesize = File.size(mypath)
			total_bytes += filesize
			puts("#{mypath} : #{filesize} bytes, #{filesize/1024}KB")
		end
	}
	
	$dirsize += total_bytes
	return total_bytes
end

dirname = ".."
dirname = gets().chomp()

if !(File.directory?(dirname)) then
	puts("#{dirname} is not a valid directory")
else
	processFiles(dirname)
	printf("Size of this directory and subdirectories is #{$dirsize} bytes, #{$dirsize/1024}KB, %0.02f MB", $dirsize/1048576.0)
end
