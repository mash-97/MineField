include Math


def a( x, y)
	x = x.to_f
	y = y.to_f
	
	(log(x*y) == ( log(x) + log(y) )) ? 1 : 0
end

def b( x, y)
	x = x.to_f
	y = y.to_f
	
	(log(x+y) == ( log(x) * log(y) )) ? 1 : 0
end

def put_a(s)
	if(s == :passed) then puts("log(a * b) == log(a) + log(b) :: passed")
	else puts("log(a * b) == log(a) + log(b) :: failed") end
end

def put_b(s)
	if(s == :passed) then puts("log(a + b) == log(a) * log(b) :: passed")
	else puts("log(a + b) == log(a) * log(b) :: failed") end
end

def simulate
	at = 0
	bt = 0
	(1..1000).each{|x|
		aac = 0
		abc = 0
		bac = 0
		bbc = 0
		
		(1..1000).each{|y|
			aac += a(x,y)
			abc += a(x, (1/y.to_f))
			bac += b(x,y)
			bbc += b(x, (1/y.to_f))
		}
		
		puts("Object: #{x} ")
		if((aac.to_f/1000) >= 0.5 || (abc.to_f/1000) == 1) then 
			put_a(:passed)
			at += 1
		else put_a(:failed) end
		
		if((bac.to_f/1000) == 1 || (bbc.to_f/1000) == 1) then 
			put_b(:passed)
			bt += 1
		else put_b(:failed) end
		
		puts
	}
	
	puts("Result: total a pass: #{at} and total b pass: #{bt}")
	puts("TRUE: ")
	if(at > bt) then 
		put_a(:passed)
		put_b(:failed)
	
	elsif(at < bt) then
		put_b(:passed)
		put_a(:failed)
	else 
		puts("SEEMS LIKE THEY ARE SAME: MEANS YOUR PROGRAM HAS BUGS !!!")
	end
end


simulate
	
gets
