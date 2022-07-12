######Prime Check#######

include Math
def primeCheck(number)
	if(number == 0 || number == 1 || number % 2 == 0)
		return false
	end
	if(number == 2)
		return true
	end
	
	limit = sqrt(number)+1
	i=3
	until(i>=limit)
		if(number % i == 0) then return false end
		i += 2
	end
	
	return true
end


number = 0
until(number == 'q') do
	print("\n\nEnter a number: ")
	number = gets.chomp
	if(primeCheck(number.to_i) == true) then puts"#{number.to_i} is a prime."
	else puts("#{number.to_i} is not a prime.") end
end
