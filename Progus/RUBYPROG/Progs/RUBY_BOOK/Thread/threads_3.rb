words = ["moshikato", "younoius", "harida"]
numbers = [243, 23, 2]

start_time = Time.new
word_thread = Thread.new{
	words.each{|word| puts word}
}

number_thread = Thread.new{
	numbers.each{|number| puts number}
}


[word_thread, number_thread].each{
	|t| t.join}
	
end_time = Time.new

puts("execution time: %.9f" % (end_time-start_time))

