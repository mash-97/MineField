TESTSTR = 'abc is not cba'

puts('----match----')
b = /[abc]/.match(TESTSTR)
p(b)

puts("\n----scan----")
a = TESTSTR.scan(/[abc]/)
p(a)

a = TESTSTR.scan(/[abc]/){
	|c|
	print(c.upcase)
}

puts
puts a

