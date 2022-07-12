begin
string = gets.chomp

case string
	when /^[a-z 0-9]*$/
		puts("Lower case")
	when /^[A-Z 0-9]*$/
		puts("Upper case")
	else 
		puts("Mixed case")
end

end until string==nil
