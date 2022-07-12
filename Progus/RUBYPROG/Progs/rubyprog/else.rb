######### else . rb ############

def doCalc(aNum)
	begin
		result = 100/(aNum.to_i())
	rescue Exception => e
		result = 0
		if(e.class == ZeroDivisionError); msg = "Error: Failed to convert the string into integer: " + e.to_s end
	else
		msg = "The result is: #{result}"
	ensure
		msg = "You entered: #{aNum}. " + msg
	end
	return msg
end

print("Enter a number: ")
number = gets().chomp()
puts(doCalc(number))
gets
