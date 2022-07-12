############ retry . rb ###############
def doCalc()
	exceptionCounter = 1
	begin
		print("Enter a number: ")
		number = gets().chomp()
		result = 100/number.to_i()
	rescue Exception => e
		puts("Error:" + e.to_s + "\nPlease try again.")
		if(exceptionCounter < 5)
			exceptionCounter += 1
			retry
		end
	else
	
		msg = "Result = #{result}"
	ensure
		msg = "You entered #{number}. " + msg
	end
	
	return msg
end

puts(doCalc)

gets