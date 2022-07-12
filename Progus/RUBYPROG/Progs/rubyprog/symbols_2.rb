def aMethod(somearg)
	p(somearg)
	puts("[class = #{somearg.class}]\n")
end

x = 1		
xsymbol = :x

puts('=Test #1--------')
puts('aMethod(x)')
aMethod(x)
puts('aMethod(:x)')
aMethod(:x)

puts('-Test #2--------')
puts('aMethod(eval(:x.id2name))')
aMethod(eval(:x.id2name))

puts('-Test #3 --------')
aMethod(xsymbol)
aMethod(:xsymbol)
aMethod(eval(:xsymbol.id2name))
aMethod(eval(:xsymbol.id2name).id2name)

puts('-Test #4 ---------')
method(:aMethod).call("")
method(:aMethod).call(eval(:x.id2name))=
puts("******")
send("aMethod", " ")
gets
