class A
	@@g = []
	def initialize
		@@g << self
	end
	def c
		puts("A:: a")
		puts(@@g.count)
	end
end

module M
	def a
		puts("M:: a")
	end
	def am
		puts("M:: am")
	end
	
	class A
		def b
			puts("M::A:: b")
		end
	end
	def aA
		A.new
	end
end

module N
	def a
		puts("N:: a")
	end
	def an
		puts("N:: an")
	end
end

module MN
	include M
	include N
end

include MN
A.new
A.new
A.new
puts A.new.c
