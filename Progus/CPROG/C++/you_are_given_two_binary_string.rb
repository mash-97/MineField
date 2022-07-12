require 'pp'

def s(k, x, y)
	xi = eval("0b#{x}")
	yi = eval("0b#{y}")
	
	s = xi+(yi*2**k)
	
	[s, s.to_s(2).reverse, s.to_s(2)]
end

def ss(x, y)
	puts("x: #{x} => #{eval("0b#{x}")}")
	puts("y: #{y} => #{eval("0b#{y}")}")
	
	puts("0 [#{s(0, x, y)}]")
	mk = 0
	r = [mk, s(mk, x, y)]
	mk += 1
	while(mk<=50) do
		puts("#{mk} [#{s(mk, x, y)}]")
		if(r[1][1] > s(mk, x, y)[1]) then
			r[0] = mk
			r[1] = s(mk, x, y)
		end
		mk+=1
	end
	return r
end

#~ x = ""
#~ y = ""

#~ while((x=gets.chomp)!=nil and (y=gets.chomp)!=nil) do
	#~ puts
	#~ p ss(x, y)
#~ end

def CC(digit, number)

	total_digits = number.to_s.length;
	count = 0;
	
	i = 1;
	pp = 10;
	p  = 1;
	
	while(i<=total_digits)
	
		count += (number / pp) * p;
	
		nmp = (number % pp);
		
		if( nmp >= digit * p && nmp <= digit * p+ (p-1))
			count += (number % p)+1;
			
		elsif(nmp > (digit*p + (p-1)))
			count += p;
		end
			
		i+=1;
		p *= 10;
		pp *= 10;
	end
	return count;
end

def countD(d, n)
	d = d.to_s
	count = 0
	(1..n).each{|x|
		count += x.to_s.split(//).count(d)
	}
	count
end

a = ""
while((a=gets)!=nil) do
	a = a.split(/ /).map(&:to_i)
	#~ s = Time.now
	#~ x = countD(a[0], a[1])
	#~ e = Time.now
	#~ puts("Time for countD: #{e-s}, #{x}")
	
	s = Time.now
	x = CC(a[0], a[1])
	e = Time.now
	
	puts("Time for countD: #{e-s}, #{x}")
end
	
