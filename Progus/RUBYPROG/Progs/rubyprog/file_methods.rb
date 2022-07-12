file_name = '2.txt'
if File.exist?(file_name) then
	puts(File.expand_path(file_name))
	puts(File.basename(file_name))
	puts(File.dirname(file_name))
	puts(File.extname(file_name))
	puts(File.mtime(file_name))
	puts("#{File.size(file_name)} byts")
else
	puts("Can't find file!")
end
gets