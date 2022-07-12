x = 1
module Foo
	x = 50
	def no_bar
		return x
	end
	
	def bar
		@x = 1000
		return @x
	end
	puts("In Foo: x = #{x}")
end

include Foo
puts(x)
#puts(no_bar)
puts(bar)
gets