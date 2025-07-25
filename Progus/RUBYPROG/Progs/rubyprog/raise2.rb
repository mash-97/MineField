######## raise2.rb ###########
begin
	raise
rescue Exception => e
	puts(e.class)
	puts("message: "+e.to_s)
end

puts

begin
	raise "An unknown exception just occurred!"
rescue Exception => e
	puts(e.class)
	puts("message: "+e.to_s)
end

puts

begin
	raise ZeroDivisionError
rescue Exception => e
	puts(e.class)
	puts("message: "+e.to_s)
end
puts

begin
	raise ZeroDivisionError.new("I'm afraid you divided by zero.")
rescue Exception => e
	puts(e.class)
	puts("message: "+e.to_s)
end

gets