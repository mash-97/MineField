######### greatest common divisor of two numbers ############
def gcdOfTwoNumbers(num1, num2)
	begin
		if(num1 % num2 == 0) then return num2 end
		return gcdOfTwoNumbers(num2, num1%num2)
	rescue Exception => e
		puts e.class
		puts e
		return 0
	end
end

puts("Enter Two Numbers: ")
num1, num2 = gets.to_i, gets.to_i
puts ("Greatest Common Divisor of #{num1} and #{num2} is #{gcdOfTwoNumbers(gcdOfTwoNumbers(num1, num2), 99)}")

gets