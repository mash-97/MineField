$workday = true
$dayHash = Hash.new("Imaginary Day")
$dayHash = {
			1 => 'Monday',
			2 => 'Tuesday',
			3 => 'Wednesday',
			4 => 'Thursday',
			5 => 'Friday',
			6 => 'Saturday',
			7 => 'Sunday'
		  }

def showDay(i)
	if i==1 then puts("It's Monday")
	elsif i==2 then puts("It's Tuesday")
	elsif i==3 then puts("It's Wednesday")
	elsif i==4 then puts("It's Thursday")
	elsif i==5 then puts("It's Friday")
	elsif i==6 then puts("It's Saturday")
	elsif i==7 then puts("It's Sunday")
	else puts("It's not a Realday") end
	dayIs(i)
end

def dayIs(i)
	(($dayHash[i] == 'Saturday') || ($dayHash[i] == 'Sunday' && ! $workday)) ?
	puts("#{$dayHash[i]} is a Holiday"):
	puts("#{$dayHash[i]} is a Workingday")
end

for i in 1...8 do
	showDay(i)
end
puts("**#{$dayHash[9]}**")
gets