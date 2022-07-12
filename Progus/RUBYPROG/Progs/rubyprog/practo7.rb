class Operation
	attr_accessor :anotherNumber
	attr_reader	  :number
	attr_writer   :number
	
	attr_accessor(:number1, :number2)
	
	def initialize(aNumber)
		@number = aNumber
	end
	
	def sum
		@number + @number1 + @number2 + @anotherNumber
	end
	
	def divide(aNumber)
		result = 0
		begin
			result = ((@number+@number1+@number2)*@anotherNumber)/aNumber
		rescue Exception => exc
			result = "infinity"
			puts(exc.class)
			puts(exc)
		end
		return result
	end
end

ob = Operation.new(100)
ob.number1 = 100
ob.number2 = 200
ob.anotherNumber = 3

puts ob.divide(0).to_f
puts ob.sum

gets