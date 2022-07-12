require("fileutils")
pat = Dir.getwd
puts("Current Directory: #{pat}")
Dir.chdir("/home/mash/Progus/RUBYPROG/Progs/RUBY_BOOK")
overwrite_prompt = true;

#get source directory
puts("FROM which directory would you like to copy the files?")
sourcedir = gets().chomp()

if !(File.directory?(sourcedir)) then
    puts("A directory called #{sourcedir} cannot be found!")
else
    #get terget dir
  puts("INTO which directory would you like to copy the files?")
  tergetdir = gets().chomp()
  
  ok = true		#if tergetdir doesn't exist...
  if !(File.directory?(tergetdir)) then
	ok = false
    puts("#{tergetdir} cannot be found!")
    puts("Would you like to create it?")
    answer = gets()
    if(answer[0].downcase == 'y') then
    	FileUtils.mkdir(tergetdir)
		ok = true
	end
   end
   if ok then
		Dir.foreach(sourcedir){
			|f|
			filepath = "#{sourcedir}\\#{f}"
			if !(File.directory?(filepath)) then
				if File.exist?("#{tergetdir}\\#{f}") then
					puts("#{f} already exists in terget directory (not copied)")
				else
					FileUtils.cp(filepath, tergetdir)
					puts("Copying...#{filepath}")
				end
			end
		}
		end
end
puts("End")
gets();
		
			
		  
