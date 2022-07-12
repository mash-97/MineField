counter = 0
commando = 1
array_of_words = []
until commando == 0
	counter += 1
	print("\n#{counter}->")
	array_of_words[counter-1] = gets.to_s
	if((array_of_words[counter-1].chomp! <=> "end") == 0) 
		commando = 0
	end
end
array_of_words[counter-1] = nil

array_of_words.compact!
array_of_words.sort!
#array_of_words.reverse!
puts("Printing ascend sorted ordered:\n")
for i in (0...array_of_words.length)
	puts"#{i+1}:: #{array_of_words[i]}"
end
gets


