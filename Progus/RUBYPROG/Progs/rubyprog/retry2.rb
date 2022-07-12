def doCalc
	tries = 0
	begin 
		print("Enter a number: ")
		number = gets().to_i()
		tries += 1
		result = 100/number
	rescue Exception => e
		msg = "Error: "+e.to_s
		puts msg
		puts("Tries = #{tries}")
		result = 0
		if(tries < 3) then retry end
	else
		msg = "Result = #{result}"
	ensure
		msg = ("You entered: #{number}. "+ msg)
	end
	
	result msg
end

puts(doCalc())

gets
		