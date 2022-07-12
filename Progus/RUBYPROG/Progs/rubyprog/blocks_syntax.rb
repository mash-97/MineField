puts("do..end")

a = [[1,2,3],[3,4,5], [6,7,8]]

a.each do 
	|a|
	puts("#{a}")
end

puts("{..}")

a.each{
	|a|
	puts("#{a}")
}
gets