salary = 2000000
season = 'summer'

happy = case
	when salary > 10000 && season == 'summer'
		puts("Yes, I really am happy!")
		'Very happy'
	when salary > 5000000 && season == 'spring' ; 'pretty happy'
	else puts ("meserable"); "meserable"
end

puts(happy + " :::")
gets