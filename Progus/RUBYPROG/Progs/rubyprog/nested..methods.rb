############ nested methods #############
class X
	def x
		print("x")
		def y
			print("y")
		end
		
		def z
			print("z")
			y
		end
		y
		z
	end
end

ob = X.new
ob.x
ob.z
gets