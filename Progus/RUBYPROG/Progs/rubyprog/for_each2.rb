#Compare for loops and each iterators with arrays and ranges

array = ['one', 'two', 'three', 'four']

#for
puts("\nfor..in..end(array)")
for s in array
	puts(s)
end

puts("\nfor..in..end(range)")
for s in 1..3
	puts (s)
end

#each
puts("\neach..do..end(array)")
array.each do |s|
	puts (s)
end

puts("\neach..do..end(range)")
(1..3).each do |s| puts end


gets