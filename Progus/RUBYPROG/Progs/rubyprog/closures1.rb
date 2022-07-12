def aFunc(aClosure)
	@hello = "hello world"
	puts("inside the aFunc function")
	aClosure.call
end

aClos = lambda{
				@hello << " yikes!"
				puts("in #{self} object of class #{self.class}, @hello = #{@hello}")
}

aFunc(aClos)
puts("outside the aFunc function")
aClos.call
aClos.call
aClos.call
aClos.call

class X
	def y(b)
		@hello = "I say, I say, I say!!!"
		puts("[In X.y]")
		puts("in #{self} object of class #{self.class}, @hello = #{@hello}")
		puts(" [In X.y] when block is called...")
		b.call					#<===watch the value of the var @hello!
	end
end

puts("===============x.y(aClos)")
x = X.new
x.y(aClos)
puts("===============self.inspect")
puts self.inspect
puts("===============x.inspect")
puts x.inspect

gets
