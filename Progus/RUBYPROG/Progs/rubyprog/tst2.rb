i = 0
a = i.to_s
until i==10 do
	puts a
	i +=1
	a<<i.to_s
	
end

puts a

puts self.inspect


puts "======================================================"
puts "======================================================"
class A
	ABC = 5
	puts "Inside A class"
	class B
		puts "Inside B class"
		class C
			def hello
				puts "Hello Ruby"
			end
			puts "Inside C class"
		end
	end
	def self.add(x, y)
		print x,"+",y,"=",x+y
	end
end
A::add(2, 7)
puts
A.add(3, 8)
puts

puts "======================================================"
puts A::ABC
puts "======================================================"
x = A::B::C.new
x.hello