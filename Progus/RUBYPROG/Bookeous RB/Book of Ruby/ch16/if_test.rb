# The Book of Ruby - http://www.sapphiresteel.com

RegEx = /def/
Str1  = 'abcdef def'
Str2  = 'ghijkl'

b = if RegEx =~ Str1 then
	puts( 'true' )
	true
else
	puts( 'false' )
	false
end
puts b

a = if RegEx =~ Str2 then
	puts( 'true' )
	true
else
	puts( 'false' )
	false
end
puts a
a = if RegEx =~ Str1 then RegEx =~ Str1 end
puts a

puts Str1.scan(RegEx)
