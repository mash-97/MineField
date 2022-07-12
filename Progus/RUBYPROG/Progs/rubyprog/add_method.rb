class Array
	define_method(:aNewMethod, lambda{|*args|puts(args.inspect)})
end

puts(Array.method_defined?(:aNewMethod))
[].aNewMethod(1,2,3)

class Array
	remove_method(:aNewMethod)
end
puts(Array.method_defined?(:aNewMethod))
[].aNewMethod(1,2,3)

gets