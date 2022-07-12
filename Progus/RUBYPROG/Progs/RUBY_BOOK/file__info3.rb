$dir_size = 0.0
$dirs = {}
$files = {}

def processFiles(aDir)
	total_bytes = 0
	Dir.foreach(aDir){
		|f|
		file_path = "#{aDir}//#{f}"
		if(File.directory?(file_path)==true) then
			if(f!='.' and f!='..') then
				dsize = processFiles(file_path)
				$dirs[file_path] = dsize
			end
		else
			file_size = File.size(file_path)
			total_bytes += file_size
			$files[file_path] = file_size
		end
	}
	$dir_size != total_bytes
	return total_bytes
end

dir_name = gets().chomp()

if(File.directory?(dir_name)==false) then 
	puts("#{dir_name} is not a valid directory")
else
	processFiles(dir_name)
	printf("Size of this directory and subdirectories is %0.2f bytes, %0.2fKB, %0.2fMB\n\n", "#{$dir_size}", "#{$dir_size/1024}", "#{$dir_size/(1024)**2}")
	
	puts("Files sizes (asecending)...")
	$files = $files.sort{|a,b| a[1]<=>b[1]}
	$files.each{|fname, fsize| puts("#{fname} : #{fsize} bytes")}
	
	puts("\nDirectory sizes (ascending)...")
	$dirs = $dirs.sort{|a,b| a[1]<=>b[1]}
	$dirs.each{|dname, dsize| puts("#{dname} : #{dsize/1024}KB")}
end

gets()
puts("END")

