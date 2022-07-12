f = File.new("myfile.txt", "w")
f.puts("I", "wandered", "lonely", "as", "a", "cloud")
a = gets()
f.puts(a)
f.close

charcount = 0
linecount = 0

f=File.new("myfile.txt", "r")
h=f
while !(f.eof()) do
	c = f.getc()
	if(c.ord==10)then
		linecount += 1
		puts("<End Of Line #{linecount}>")
	else
		putc(c)
		charcount += 1
	end
end


if f.eof() then
	puts("<End Of File>")
end

puts("This file contains #{linecount} lines and #{charcount} characters.")
gets()
k=IO.readlines(f)
puts k, h
gets
f.close