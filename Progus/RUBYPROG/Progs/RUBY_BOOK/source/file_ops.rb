puts("Testing File.exist?...")
if File.exist?("C") then
	puts("Yup, you have a C:\\ directory")
else 
	puts("Eeek! Can't find the C:\\ drive!")
end

if File.exist?("Z:\\") then
	puts("Yup, you have a Z:\\ directory")
else 
	puts("Eeek! Can't find the Z:\\ drive!")
end

def dirOrFile(aName)
	if(File.directory?(aName)) then
		puts("#{aName} is a directory")
	else 
		puts("#{aName} is a file")
	end
end

puts("\ndirOrFile...")
dirOrFile("file_ops.rb")
dirOrFile("C")

def dirOrFile2(aName)
	if(File.exists?(aName)) then
		if(File.directory?(aName)) then
			puts("#{aName} is a directory")
		else 
			puts("#{aName} is a file")
		end
	else
		 puts("#{aName} can't be found!")
	end
end

puts("\ndirOrFile2...")
dirOrFile2("file_ops.rb")
dirOrFile2("C")
dirOrFile2("gribbitsnorp.xyz")
gets

	

