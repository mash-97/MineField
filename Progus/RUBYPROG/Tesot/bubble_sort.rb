def bubble_sort(a)
	len = a.length
	i = 0
	while(i<len) do
		j = len-1
		while(j!=i) do
			if(a[j] < a[j-1]) then a[j], a[j-1] = a[j-1], a[j] end
			j -= 1
		end
		puts("#{i}: #{a}")
		i += 1
	end
end

a = gets.chomp.split(' ').map(&:to_i)
bubble_sort(a)
print a
		
