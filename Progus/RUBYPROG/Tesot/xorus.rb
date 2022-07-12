def xorus(n)
	count = 0
	a = 0
	for i in 1..n do
		yield(a^i)
		a = a^i
	end
end

def x(n)
	a = 0
	xorus(n){|i| a+=i}
	a
end

def adn(a, d, n)
	(n*a) + (n*n*d)/2 - (n*d)/2
end

def sum_of_xorus(n)
	n_by_2 = (n)/4
	n_mod_2 = (n)%4
	
	for_four = adn(4,4, n_by_2)
	for_three =  adn(3,4, n_by_2)
	
	sum =  for_four+ for_three+ n_by_2
	if(n_mod_2 >= 1) then sum += 1 end
	if(n_mod_2 >= 2) then sum += (3 + n_by_2 * 4) end
	
	return sum
end

def left_to_right(l, r)
	return sum_of_xorus(r) - sum_of_xorus(l-1)
end

#~ def left_right_xorus_sum(left, right)
lc = 1000000000
i = lc
l = 10000000000
rc = 10000000000000
j = rc
r = 1000000000000000
IO.foreach("/home/mash/Testo/xorus.txt"){|line|
	n = line.to_i
	if(left_to_right(i, j) != n) then 
		puts("Not matched! #{i}--#{j}, rb: #{left_to_right(i, j)}, c: #{n}")
		gets()
	else
		puts("Matched !")
	end
	j+=1
	if(j>r) then
		j=rc
		i += 1
	end
	
	if(i>l) then break end
}
#~ (0..100000000000).each{|x| 
	#~ if(x(x) != sum_of_xorus(x)) then 
		#~ puts("Not matched for #{x}: x(#{x}): #{x(x)} and sum_of_xorus(#{x}): #{sum_of_xorus(x)}")
		#~ gets()
	#~ else puts("Matched for #{x}") end
#~ }
