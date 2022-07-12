class PPP
	
	public
		def pub
			puts("This is public property")
		end
		
		def protto(a)
			puts("Inside protto:")
			puts("Start: ")
			print("a.pub: "); a.pub;
		#	print("a.priv: "); a.priv;
			print("a.prot: "); a.prot;
			puts("End.")
		end
	private
		def priv
			puts("This is private property")
		end
		
	protected
		def prot
			puts("This is protected property")
		end
end

class P
	def initialize(a_ppp_object)
		puts("Inside P: ")
		puts("Start:")
		a_ppp_object.pub
		puts("End.")
	end
end

pob1 = PPP.new
pob2 = PPP.new
puts("pob1: #{pob1} and pob2: #{pob2}")
puts("\npob1.protto(pob2): ")
pob1.protto(pob2)
puts("\npob2.protto(pob1): ")
pob2.protto(pob1)
