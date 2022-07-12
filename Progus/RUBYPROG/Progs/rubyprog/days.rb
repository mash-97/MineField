def dayIs(aDay)
	working_overtime = true
	if aDay == "Saturday" or aDay == "Sunday" and not working_overtime
		dayType = "Holiday"
		puts("Hurrah!")
	else
		dayType = "Working day"
	end
	return dayType
end

#Different operators produce different results
def dayIs2(aDay)
	working_overtime = true
	if aDay == "Saturday" || aDay == "Sunday" && !working_overtime
		dayType = "Holiday"
		puts("Hurrah!")
	else 
		dayType = "Working day"
	end
	return dayType
end

day1 = "Monday"
day2 = "Saturday"
day3 = "Sunday"
print(day1 + " is a "+dayIs(day1)+"\n")
print(day2 + " is a "+dayIs(day2)+"\n")
print(day3 + " is a "+dayIs(day3)+"\n")

puts("Using different approach")

print(day1 + " is a "+dayIs2(day1)+"\n")
print(day2 + " is a "+dayIs2(day2)+"\n")
print(day3 + " is a "+dayIs2(day3)+"\n")

gets