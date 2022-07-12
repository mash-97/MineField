include Math
class Namosh
	@@array_of_prime = []
	def initialize(aNumber)
		@number = aNumber	
	end
	
	def checkPrime
		if(@number == 2) 
			return true
		elsif(@number == 0 || @number == 1)
			return false
		end
		@sqrt_number = sqrt(@number)
		for i in(3..@sqrt_number)
			if(@number % i == 0)
				return false
			end
			i+=2
		end
		return true
	end
	
	def checkPalindromity
		number_string = @number.to_s
		middle = number_string.length/2.to_i
		j = number_string.length-1
		for i in (0...middle)
			if(number_string[i] != number_string[j]) then return false end
			j -= 1
		end
		return true
	end
end	
		
k = 0
until k == 10
	num = gets.to_i	
	number1 = Namosh.new(num)
	if(number1.checkPalindromity == true) then puts("It's a palindrome number.")
	else puts("It's not a palindrome.") end
	
	if(number1.checkPrime == true) then puts("The number is prime.")
	else puts("The number is not prime.") end
	k+=1
end
gets