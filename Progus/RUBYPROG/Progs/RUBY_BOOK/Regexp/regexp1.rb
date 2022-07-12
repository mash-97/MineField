r1 = Regexp.new('^[a-z]*$')
r2 = /^[a-z]*$/
r3 = %r{^[a-z]*$}

#Hello This is regexp1
p(r1)
p(r2)
p(r3)

def test(areg, astr)
	if(areg =~ astr) then puts("all lower case")	#Yo this is regexp1
	else puts("not all lower case") end
end

test(r1, "hello")
test(r2, "hello")
test(r3, "HellO")
