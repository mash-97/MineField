def foo(b)
	puts("---in foo---")
	a = 'foo'
	if block_given?
		puts("(Block passed to foo)")
		yield(a)
	else
		puts("(no block passed to foo)")
	end
	puts("In foo, arg b = #{b}")
	return "returned by "<<a
end

def bar
	puts("===in bar===")
	a = 'bar'
	if block_given?
		puts("(Block passed to bar)")
		yield(a)
	else
		puts("(no block passed to bar)")
	end
	return "returned by "<<a
end

#================Syntax "A" -do..end================
puts('---(A)do block---')
#calls foo with block
foo bar do |s| puts(s) end

puts

#=================Syntax "B" -{} ===================
puts('---(B) curly braces block---')
#calls bar with block
foo bar{|s| puts(s)}
gets
