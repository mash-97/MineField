Document = <<PRIME
			A program to find out all the prime numbers between a specified limit. The method here used is Sieve Erothesnes.
PRIME

#Sieve Erothesnes Method To Find Out Primes

$primes = Array.new(300000)
$nPrime = 0

#1 if not prime, 0 if prime.
$mark = Array.new(1000002, 0)

def sieveErothesnes(n)
	include Math
	limit = sqrt(n*1.0) + 2
	
	#1 is not prime, you can also mark 0.
	$mark[1] = 1
	
	#almost all the evens are not prime.
	
	i = 4
	while(i <= n) 
		$mark[i] = 1
		i += 2
	end
	
	#2 is prime
	$primes[$nPrime] = 2
	$nPrime = 1		
	
	i=3
	while(i <= n)
		#if not prime, no need to do "multiple cutting"
		if($mark[i] == 0)
			$primes[$nPrime] = i
			$nPrime += 1
			
			#if we don't do it, following i*i may overflow.
			if i <= limit
				#loop through all odd multiples of i greater than i*i.
				j = i*i
				while(j <= n)
					#mark j not prime.
					$mark[j] = 1
					j += i*2
				end
			end
		end
		i += 2
	end
end

n = 0
puts("Enter the limit: ")
n = gets.to_i	
sieveErothesnes(n)
puts("Showing all the primes under #{n+1}")
for i in (0...$nPrime) do print("#{$primes[i]} : ") end
puts
number = 0
command = 0
while(command != 1)
	puts("Enter a number between 1 to #{n} to check if prime:")
	number = gets.to_i
	if !(number > 0 and number <= n)
		command = 1
	elsif($mark[number] == 0)
		puts("The number #{number} is prime.")
	else puts("It's not prime.") end
end

