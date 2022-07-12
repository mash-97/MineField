startdir = Dir.getwd
puts("We get to start from here #{startdir}")

begin
	Dir.chdir("X:\\")
	puts(`dir`)
rescue Exception => e
	puts e.class
	puts e
ensure
	Dir.chdir(startdir)
	puts(`dir`)
end
puts("We get to end down here #{Dir.getwd}")
gets