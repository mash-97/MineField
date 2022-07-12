outputs = File.readlines("countingSort.output")[0].chomp.split(/ /).map(&:to_i)
co = outputs.clone
co.sort!
puts("Test Size: #{co.length}")
puts(co==outputs)
gets()



f = File.open("countingSort.input", "w")

size = 100000
array = []
hash = {}

size.times{
	a = rand(-size..size)
	if not hash[a] then
		hash[a] = true
		array << a
		puts("Writing #{a}")
	end
}

f.puts(array.length)
array.each{|x| f.printf("%d ", x)}
f.puts

f.close

