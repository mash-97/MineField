$Limit_of_number = 1000000
#To keep all the primes.
$Prime = Array.new($Limit_of_number/10)				#Array of Prime.
$Number_of_prime = 0								#Concurrent number of Total Prime.

#For marking the number as prime.
$Mark = Array.new($Limit_of_number, true)

#Function to search all the prime below n+1 by Sieve Erothesness Method.
def sieveErothesness(n)
	if(n > $Limit_of_number) then return "Greater than the limit" 
	elsif(n < 1) then return "The number is smaller then 1" end
	
	#Limit to go through loop.
	limit = Math.sqrt(n)+2
	
	#Marking 1 is not prime.
	$Mark[1] = false
	
	#Marking 2 is prime.
	$Mark[2] = true
	$Prime[$Number_of_prime] = 2
	$Number_of_prime += 1
	
	#Marking all the even numbers except 2 as not prime.
	i = 4
	until(i>=n) do
		$Mark[i] = false
		i += 2
	end
	
	#Don't distrub, the 'ant' at busy to search 'food' Prime.
	#Loop through all the odds to find all the primes.
	i = 3
	while(i <= n) do
	
		#If i is prime. 
		if($Mark[i] == true) then
		
			#Marking the i as prime.
			$Mark[i] = true
			$Prime[$Number_of_prime] = i
			$Number_of_prime += 1
			
			#Because unprsence of this 'cop' can cause to overflow.
			if(i <= limit) then
				
				#Gotta mark non prime as false.
				#Loop through all the odd that is multiples of i, greater than i*i and
				#between the n limit.
				j = i*i
				while(j <= n) do
					$Mark[j] = false			#Mark j not prime.
					j += i*2
				end
			end
		end
		i+=2
	end 										#End of the 'ant' loop.
end

#Function to check a number's primeness.
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


print "Enter a number between 1 to #{$Limit_of_number}: "
n = gets.to_i
sieveErothesness(n)
puts "Printing all the primes between 1 and #{n}:"
for i in (0...$Number_of_prime) do
	print("#{$Prime[i]} :: ")
end
puts
puts("Check a number between 1 and #{n} if it's prime:")
puts("For prime check by default type 'd'")
puts("For prime check by method type  'm'")
puts("For quit type 				  'q'")
commando = 'a'
until(commando == 'q') do
	print("\ncommand::")
	commando = gets.to_s.chomp
	if(commando != 'q') 
		print("Enter the number: ")
		number = gets.to_i
	elsif(commando == 'q') then break end
	
	case(commando)
		when 'd'; 
			if($Mark[number] == true) then puts("#{number} is a prime.")
			else puts("#{number} is not a prime.") end
		when 'm';
			if(primeCheck(number) == true) then puts("#{number} is a prime.")
			else puts "#{number} is not a prime." end
		else puts("Wrong input: Try Again--") 
	end
end
gets