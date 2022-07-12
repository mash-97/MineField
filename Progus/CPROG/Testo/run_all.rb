
files = Dir.glob("*").select{|f| f if f  =~ /^.+\.c/}


files.each{|f|
	puts()
	puts("File name: #{f}")
	if f =~ /\.cpp$/ or f =~ /\.cp$/ then
		puts("Executing `g++ -o #{f.split(".c")[0]}.o #{f}")
		command = "g++ -o #{f.split(".c")[0]}.o #{f}"
		result = `#{command}`
		puts("Result: #{result}")
		
		puts("Executing `./#{f.split(".c")[0]}.o")
		result = `./#{f.split(".c")[0]}.o`
		puts("Result: #{result}")
		puts
	else 
		puts("Executing `g++ -o #{f.split(".c")[0]}.o #{f}")
		command = "g++ -o #{f.split(".c")[0]}.o #{f}"
		result = `#{command}`
		puts("Result: #{result}")
		
		puts("Executing `./#{f.split(".c")[0]}.o")
		result = `./#{f.split(".c")[0]}.o`
		puts("Result: #{result}")
		puts
	end
}
	
