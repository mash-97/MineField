class A
	def a
		puts "This is Prior A.a method"
	end
end

class B < A
	def b
		puts "This is Prior B.b method"
	end
end

class A
	def a1
		puts "This is modified A.a method"
	end
end

class B
	def b1
		puts "This is modified B.b1","whithout declaring B<A"
	end
end

a = A.new
b = B.new

a.a1
a.a

b.b1
b.b
puts
puts
b.a1
gets