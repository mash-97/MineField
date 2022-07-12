########## disk err .rb ##############
def showFamily(aClass)
	if(aClass != nil)
		puts("#{aClass}")
		showFamily(aClass.superclass)
	end
end

def chDisk(aChar)
	startdir = Dir.getwd
	begin 
		Dir.chdir("#{aChar}:\\")
		puts(`dir`)
	rescue Exception => e
		puts e
		puts e.class
	ensure
		Dir.chdir(startdir)
	end
end

chDisk("D")
chDisk("X")
chDisk("ABC")

gets
	