class Aclass
	def initialize(aNumber, anotherNumber)
		@num1 = aNumber
		@num2 = anotherNumber
	end
	
	def dispAdd
		print "\n",@num1," + ",@num2," = ", @num1+@num2,"\n"
	end
	
	def disp
		puts self
		p self.inspect
		p self.class
	end
end

a = Aclass.new(1,1)
b = Aclass.new(2,2)
c = Aclass.new(3,3)

arrayOfObjects = a, b, c
 
i=1
arrayOfObjects.each{
	|array|
	puts"\n\nObject no: #{i}"
	array.dispAdd
	array.disp
	i += 1
}

gets