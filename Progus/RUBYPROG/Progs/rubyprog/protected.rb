######### Protected . rb ##########
class MyClass
	private
	def priv(aStr)
		return aStr.upcase
	end
	
	protected
	def prot(aStr)
		return aStr << '!!!'
	end
		
	public
	def exclaim(anOb) 					#calls a protected method
		puts(anOb.prot("This is a #{anOb.class} - hurrah"))
	end
	
	def shout(anOb)						#class a private method
		puts(anOb.priv("This is a #{anOb.class} - hurrah"))
	end
end

class MyOtherClass < MyClass

end

class MyUnrelatedClass

end


#MyClass
myob = MyClass.new

#MyOtherClass
myotherob = MyOtherClass.new

#MyUnrelatedClass
myunrelatedob = MyUnrelatedClass.new

#calls a public method (shout) with ob of descendent class which calls a private method
#(priv) - that's NOT OK!
#p "-1"
#myob.shout(myob)

#class a public method (shout) with ob of ancestor class which calls a private method
#(priv) - that's NOT OK!
#p "-2"
#myotherob.shout(myotherob)

#calls a public method (exclaim) which calls a protected method (prot) with a descendent
#class - that's OK!
p "1"
myob.exclaim(myotherob)
p "2"
myob.exclaim(myob)
#calls a protected method with an ancestor class - that's OK!
p "3"
myotherob.exclaim(myob)
p "4"
myotherob.exclaim(myotherob)
#This won't work
#myob.exclaim(myunrealtedob)

gets