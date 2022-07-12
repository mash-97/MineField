c = 7
count = 0
 
y = 0
n = 0

while(count<=10) do
	a = rand(100)
	b = rand(100)
	
	ac = a%c
	bc = b%c
	
	acbcC = (ac*bc)%c
	
	abc = (a*b)%c
	puts
	puts
	puts("COUNT = #{count+1}")
	puts("a = #{a}, b = #{b}, c = #{c}")
	puts("a%c = #{ac}, b%c = #{bc}, a*b = #{a*b}")
	puts("\n#((a%c) * (b%c)) % c = #{acbcC}")
	puts("#(a*b) % c = #{abc}")
	puts
	puts
	
	if(acbcC == abc) then 
		puts("%% ((a%c) * (b%c)) % c == (a*b) % c")
		puts("%% #{acbcC} = #{abc}")
		y+=1
	else
		puts("%% ((a%c) * (b%c)) % c != (a*b) % c")
		puts("%% #{acbcC} != #{abc}")
		n+=1
	end
	count+=1
end

puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
if(y==count) then puts("The formula ((a%c) * (b%c)) % c = (a*b) % c is CORRECT!") 
else puts("The formula ((a%c) * (b%c)) % c = (a*b) % c is  INCORRECT!") end
puts("\nY = #{y}")
puts("N = #{n}")
puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
gets()
