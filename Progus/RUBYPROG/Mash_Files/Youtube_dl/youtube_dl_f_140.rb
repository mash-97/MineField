
puts("There are total : #{ARGV[0].split.length} in ARGV")


ARGV[0].split.each{|x|
	puts
	puts("Going to download from: #{x}")
	puts
	a = "youtube-dl -f 140 " + x
	begin
		`#{a}`
	rescue
		puts("Error: #{$!}")
	end
}
	
