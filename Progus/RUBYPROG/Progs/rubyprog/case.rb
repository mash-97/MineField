def showDay(i)
	case(i)
		when 1 then puts("It's MOnday.")
		when 2 then puts("It's Tuesday.")
		when 3 then puts("It's Wednesday.")
		when 4 then puts("It's Thursday.")
		when 5 then puts("It's Friday.")
		when 6 then puts("It's Saturday.")
		when 7 then puts("It's Sunday.")
		else puts("That's not a real day!")
	end
end

begin
	command = gets
	command.chomp!
	showDay(command)
end while command != "E"
gets