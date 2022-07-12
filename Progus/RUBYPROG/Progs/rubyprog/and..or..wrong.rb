def dayIs(aDay)
	working_overtime = true
	if aDay == "Sunday" and not working_overtime or aDay == "Saturday"
		dayType = "Holiday"
		puts("Hurrah")
	else
		dayType = "Working Day"
	end
	return dayType
end

day1 = "Monday"
day2 = "Saturday"
day3 = "Sunday"
print(day1 + " is a "+ dayIs(day1)+"\n")
print(day2 + " is a "+ dayIs(day2)+"\n")
print(day3 + " is a "+ dayIs(day3)+"\n")

gets