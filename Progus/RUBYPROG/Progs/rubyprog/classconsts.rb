# The Book of Ruby - http://www.sapphiresteel.com

class X
	A = 10
	
	class Y
		def xyz
			puts( "goodbye" )
		end
	end
	
	def self.abc
		puts("hello")
	end
	def abc
		puts ("Yossuup!")
	end
	def add= (x)
		print x,"+",9,"=",x+9
	end
end

puts( X::A )
X::abc		# you may also access class methods with ::
X.abc		# though a single dot also works here!

ob = X::Y.new
ob.xyz
o = X.new
o.abc
puts "======================================================"
o.add = 8