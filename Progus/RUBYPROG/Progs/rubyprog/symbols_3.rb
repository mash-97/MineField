def aMethod(arg)
	print("I say: "<<arg)
end

this_is_a_method = method(:aMethod)

puts(this_is_a_method)
puts("#{this_is_a_method.class}")
this_is_a_method.call("hello world")

gets