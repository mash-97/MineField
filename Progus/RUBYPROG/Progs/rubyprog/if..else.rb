def dayIs  (aDay)
	if aDay == 'Saturday' or aDay == 'Sunday'
		dayType = 'Weekend'
	else
		dayType = 'Weeday'
	end
	return dayType
end

day1 = 'Monday'
day2 = 'Saturday'

print("The day "+ day1 + " is "+ dayIs(day1)+".\n")
print("The day "+ day2 + " is "+ dayIs(day2)+".\n")

gets