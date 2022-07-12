input = ""
puts("How much do you want to earn per hour?")
while input != 'q'
	print("Enter a number between 1 and 800 or for 'q' to quite.\n?-")
	input = gets.chomp
	if input == 'q'
		puts("Bye Dude!")
	elsif input.to_i >= 1 and input.to_i <= 800
		puts("Yep! We can afford that, come up Bro....")
	elsif input.to_i > 1000
		puts("Dude! That's a high pay to afford.")
	elsif input.to_i > 800 and input.to_i <=1000
		puts("Ooo! That's quite a high, but we can afford that.")
	else
		puts("You should remember that number between 1 and 1000.")
	end
end
