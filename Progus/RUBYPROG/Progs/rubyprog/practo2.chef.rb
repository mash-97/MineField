t=gets.to_i
while(t>=1 && t<=100) do
	a,b,n = gets.split.map(&:to_i)
	if(a>=1 && b>=1 && a<=1000000000 && b<=1000000000)then
		c = a
		d = b
		s = 0
		while(n>=1 && n<=1000000000) do
			if(s==0) then c*=2;s=1 
			else d*=2;s=0 end
			n-=1
		end
		if(c>d)then puts(c/d)
		else puts(d/c) end
	end
	t-=1
end