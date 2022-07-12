############ multi exceptions . rb ############
def calc(val1, val2)
	begin
		result = val1/val2
	rescue Exception => exceptions
		puts(exceptions.class)
		puts(exceptions)
		result = nil
	rescue TypeError, NoMethodError => exceptions
		puts(exceptions.class)
		puts(exceptions)
		puts("One of the value is not a number!")
		result = nil
	end
	
	return result
end

calc(20,0)
puts
calc(20, "100")
puts
calc("100", "100")
gets