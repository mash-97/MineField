# The Book of Ruby - http://www.sapphiresteel.com

# read Marshal version from file

f = File.open('test2.sav')
vMajor = f.getc().ord
vMinor = f.getc().ord
f.close

# Try experimenting with other version numbers
#vMajor = 5
#vMinor = 7
#vMinor = 9

puts("File: Marshal Version=#{vMajor}:#{vMinor}" )
puts("Current Marshal Version=#{Marshal::MAJOR_VERSION}:#{Marshal::MINOR_VERSION}"  )

if vMajor == Marshal::MAJOR_VERSION then
	puts( "Major version number is compatible" )
	if vMinor-1 == Marshal::MINOR_VERSION then
		puts( "Minor version number is compatible" )
	elsif vMinor-1 < Marshal::MINOR_VERSION then
		puts( "Minor version is lower - old file format" )
	else
		puts( "Minor version is higher - newer file format" )		
	end
else
	puts( "Major version number is incompatible" )
end
