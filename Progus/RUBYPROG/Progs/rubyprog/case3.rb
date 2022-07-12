def showDay(i)
	case(i)
		when 1; puts("It's Monday.")
		when 2; puts("It's Tuesday.")
		when 3; puts("It's Wednesday")
		when 4; puts("It's Thursday.")
		when 5 then puts("It's Friday.")
		when 6,7,8;
		puts("It's Sunday.") if i==6
		puts("It's Saturday.") if i==7
		puts("It's the weekend.")
		when 5;
		puts("It's Friday all over again.")
		else 
		puts("That's not a real day.")
	end
end

for i in 1...10 do
	print i," "
	showDay i
end
gets
		
		