array = ['one', 'two', 'three', 'four']

#While loop
puts("\nwhile..end")
i = 0
while i < array.length
	puts(array[i])
	i+=1
end

puts("\nbegin..end while")
i = 0
begin
	puts(array[i])
	i +=1
end while i < array.length

#until
puts("\nuntil..end")
i = 0
until i == array.length
	puts array[i]
	i += 1
end
i==0
puts("\nbegin..end while")
begin
	puts array[i]
	i += 1
end until i == array.length

puts("\nfor..in..end")
for s in array
	puts s
end
#each
puts("\neach.do..end")
array.each do |s| puts s end

#loop
puts("\nloop(do..end)")
i = 0
loop do 
	puts(array[i])
	i += 1
	if(i==array.length) then
		break
	end
end

i = 0
puts("\nloop(curly braces)")
loop{
	puts(array[i])
	i+=1
	if(i==array.length) then break end
}


gets