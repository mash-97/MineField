c = 7
count = 0
n = 0
y = 0
while(count<=100) do
	a = rand(100)
	b = rand(100)
	puts
	puts
	puts("#{count+1}")
	puts("a = #{a}, b = #{b}, c = #{c}")
	aa = a%c
	bb = b%c
	aabb = aa*bb
	aaabbb = (aa*bb)%c
	ab = (a*b)%c
	puts("a%c = #{aa}, b%c = #{bb}")
	puts("(a%c)*(b%c) = #{aabb}")
	puts("((a%c)*(b%c))%c = #{aaabbb}")
	puts("(a*b)%c = #{ab}")
	
	if(aabb == ab) then
		puts("##(a%c) * (b%c) == (a*b) % c")
		n+=1
	elsif(aaabbb == ab) then
		puts("##(a%c) * (b%c) != (a*b) % c")
		puts("%%((a%c)*(b%c))%c == (a*b) %c")
		y+=1
	end
	count+=1
end
puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
if(y>=n) then puts("\n\nSo the formula ((a%c) * (b%c))%c = (a*b) % c is CORRECT!\n\n")
else puts("\n\nSo the formula (a%c) * (b%c) = (a*b) % c is INCORRECT!\n\n") end
puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
puts("Y = #{y}")
puts("N = #{n}")
gets()
