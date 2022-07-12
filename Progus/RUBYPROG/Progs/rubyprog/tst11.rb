begin
	print("Enter a number: ")
	number = gets.to_i
	result = 100/number
rescue Exception => e
	a = e
	b = e.to_s
	c = e.class
	d = e.class.to_s
	p a
	p b
	p c
	p d
	puts
	p e
	p e.class
ensure
	puts"The result is : #{result}"
end

gets