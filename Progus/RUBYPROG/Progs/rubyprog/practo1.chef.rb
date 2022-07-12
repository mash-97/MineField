t=gets.to_i
while(t>=1 && t<=1000) do
	a,b,c,d=gets.split.map(&:to_i)
	#if(a>=1 && a<=10000 && b>=1 && b<=10000 && c>=1 && c<=10000 && d>=1 && d<=10000) then
		if((a+b == c+d) || (a==b && c==d)) then puts("YES") 
		else puts("NO") end
	#end
	t-=1
end