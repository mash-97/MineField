count = 0
File.foreach('regexp1.rb'){
	|line|
	line.scan(/[^ \n\t]+/).each{
		|word|
		count+=1
		puts("[#{count}]: #{word}")
	}
}

puts
puts("There are #{count} words in the file")
