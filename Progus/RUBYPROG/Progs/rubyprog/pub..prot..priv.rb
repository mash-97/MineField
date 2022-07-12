###########pub..pro..priv.rb###########
class MyClass
	private
		def priv
			puts("Private")
		end
		
	protected
		def prot
			puts("Protected")
		end
	
	public
		def pub
			puts("Public")
		end
		
		def useOb(anOb)
			anOb.pub
			anOb.prot
			#anOb.priv
		end
end

myob = MyClass.new
myob2 = MyClass.new
#myob.pub
#myob.prot
#myob.priv

myob.useOb(myob2)

gets