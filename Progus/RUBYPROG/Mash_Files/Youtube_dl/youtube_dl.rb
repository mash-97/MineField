def download_by_ydl(strings, format)
	count = 0
	strings.each{ |x| 
		begin
			if((Regexp.new("https://www.") =~ x)==nil) then
				puts("Invalid url: #{x}")
				next
			end
			
			puts("---> downloading: #{x}")
			`gnome-terminal --window -- youtube-dl -f #{format} #{x}`
			
		rescue 
			puts("#Error happend: #{$!}")
		else
			puts("---> downloaded: #{x}")
			puts
			count += 1
		end
	}
	return count
end


strings = []
puts("Enter files urls: ")
while((s=gets) != nil) do 
	if(s!=nil) then s.chomp! end
	if(s!=' ' and s!=nil and not s.empty?) then strings << s.chomp end
end


puts
puts
puts("===> There are #{strings.length} files to download <===")
print("Enter format: ")
format = gets.chomp

puts
puts
total_downloadeds = download_by_ydl(strings, format)
puts("\n====> Total #{total_downloadeds} files downloaded <====\n")
gets
