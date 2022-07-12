def a(hash)
	
	begin 
		hash.sort{
			|a,b|
			puts("a.key: #{a[0]}  ::  b.key: #{b[0]}")
			puts("a.value: #{a[1]}  ::  b.value: #{b[1]}")
			a.to_s <=> b.to_s
		}
		
		hash.each{|k,v| puts("#{k.to_s} => #{v.to_s}") }
	rescue
		puts("Error: #{$!}")
	end
	
end

3.times{

	a = gets.chomp
	b = gets.chomp
	c = gets.chomp
	
	if(c == 'hash') then a(a: a, b: b)
	elsif(c == 'string') then a(a+" "+b)
	else puts("Undefined !") end

}
