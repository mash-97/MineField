words = ["hello", "world", "goodbye", "mars"]
numbers = [1,2,3,4,5,6,7,8,9,10]

start_time = Time.new
#puts("Start: %10.9f" % start_time)

Thread.new{
	words.each{|word| puts word}
}

Thread.new{
	numbers.each{|number| puts number}
}
sleep(5)
end_time = Time.new

#puts("End: %10.9f" % end_time)

total_time = end_time - start_time
puts("Total Time: %10.9f" % total_time)


