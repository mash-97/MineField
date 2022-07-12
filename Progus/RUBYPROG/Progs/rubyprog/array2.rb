def hello 
	return "Hello World"
end

x = [1+2, hello]			#array containing an expression, a methodcall and a string
puts(x.inspect) 				#Note: if you are not using Windows, you may need to change `dir` to command that is understood by your operating system
p(x)

y = %w(this is an array of string)
puts(y.inspect)
p y

a = Array.new
puts("Array.new: " << a.inspect)

a = Array.new(2)
puts("Array.new(2): "<<a.inspect)


p("--------------------------------")
p("--------------------------------")
a = Array.new(2, "hello world")
puts %?Array.new(2, "hello world"): ? << a.inspect

puts ("Array.new(2, \"hello world\")->a[0]: ")<<a[0]
puts ("Array.new(2, \"hello world\")->a[1]: ")<<a[1]

p ("*******************************")
p ("*******************************")
a = Array.new(2)
a[0] = Array.new(2, "hello")
a[1] = Array.new(2, "world")
puts %?Array.new(2): ? << a.inspect
puts %^Array.new(2)->a[0] = Array.new(2,"hello"): ^<<a[0].to_s
puts %^\t\ta[0][0] : ^ << a[0][0]
puts %^\t\ta[0][1] : ^ << a[0][1]
puts %^Array.new(2)->a[1] = Array.new(2, "world"): ^<<a[1].to_s
puts %^\t\ta[1][0] : ^ << a[1][0]
puts %^\t\ta[1][1] : ^ << a[1][1]


a = Array.new([1, 2, 3])
puts(a.inspect)				# = p(a)

#Note: in the above example, if you pass an array to new() without 
#putting it in round brackets, you must leave a space between 'new' and the opening square bracket.
#This works:
#		a = Array.new [1,2,3]
#This doesn't! 
#		a = Array.new[1, 2, 3]

gets
getss