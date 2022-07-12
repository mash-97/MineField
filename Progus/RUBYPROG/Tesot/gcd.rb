def gcda(a)
	include Math
	result = a[0].gcd a[1]
	a[2...a.length].each{|x|
		result = result.gcd(x)
	}
	return result
end

def gcdb(a, b)
	steps = 0
	temp = b
	while(b!=0) do
		b = a%b
		a = temp
		temp = b
		steps+=1
	end
	return [a, steps]
end

def gcdc(a, b)
	steps = 0
	if(b==0 or a==b) then return a end
	if(b>a) then a,b = b,a end
	while(a!=b) do
		steps += 1
		if(b==0) then break end
		if(a>b)
			a = a-b
		else
			b = b-a
		end
	end
	return [a, steps]
end

def gcdbb(a)
	result = gcdb(a[0], a[1])
	a[2...a.length].each{|x| result = gcdb(result, x)}
	return result
end

def gcdcc(a)
	result = gcdc(a[0], a[1])
	a[2...a.length].each{|x| result = gcdc(result, x)}
	return result
end

print("Enter numbers: ")
a = gets.chomp.split(' ').map(&:to_i)

#~ puts("gcd of #{a} is #{gcda(a)}")
bs = gcdbb(a)
cs = gcdcc(a)

puts("gcd of #{a} is #{bs[0]} :: steps: #{bs[1]}")
puts("gcd of #{a} is #{cs[0]} :: steps: #{cs[1]}")
