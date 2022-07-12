#! /usr/bin/ruby

def minimumCoins(coins, sum, minimum_coins)
	return minimum_coins if coins.length == 0 or sum == 0
	
	#~ puts("coins: #{coins.to_s}, sum: #{sum.to_s}, minimum_coins: #{minimum_coins.to_s}")
	#~ puts
	indx = 0
	result = nil
	while indx < coins.length do
		if coins[indx] != nil and sum-coins[indx] >= 0 then
			coin = coins[indx]
			coins[indx] = nil
			temp = minimumCoins(coins, sum-coin, minimum_coins + [coin])
			coins[indx] = coin
			
			result = temp if (temp!=nil) and (result==nil or result.length > temp.length)
		end
		indx += 1
	end
	
	return result
end


require 'mashz'
require 'fileutils'

def beep(*freqs)
	freqs.each{|f|
		`beep -f #{f}`
	} 
end

def playic(string)
	 note_hash = { :C  =>       261.6,
       :c    =>   277.2,
       :D     =>    293.7,
       :d    =>   311.1,
       :E      =>   329.6,
       :F      =>   349.2,
       :f     =>   370.0,
       :G      =>   392.0,
       :g     =>   415.3,
       :A      =>   440.0,
       :a     =>   466.2,
       :B      =>   493.9,
       :J      =>   523.2, 
       :z => 3333
     }
     string.split('').each{|n| `beep -f #{note_hash[n.to_sym]}`}
end

def uniqFin(basename, directory=Dir.pwd())
	return nil if not Dir.exists?(directory)
	ext = File.extname(basename)
	file_name = basename
	count = 1
	
	while File.exists?(File.join(directory, file_name)) do 
		if ext.to_s.length != 0 then
			file_name = basename.sub(ext, count.to_s+ext)
		else
			file_name = basename+count.to_s
		end
		count += 1
	end
	
	return file_name
end

def cprFilex(directory, destination, regx)
	# check directory
	if not Dir.exists?(directory) then
		puts("source directory: #{directory} doesn't exist")
		return nil
	end
	# check destination
	if not Dir.exists?(destination) then
		puts("destination directory: #{destination} doesn't exist")
		puts("Trying existifying the D directory: #{destination}")
		FileUtils.mkdir(destination)
		return nil if not Dir.exists?(destination)
	end
	
	# create tmp timestamp dir
	buff = File.join(destination, "tmp_#{(a=Time.now.hash )* (a.positive? ? 1 : -1)}")

	begin
		FileUtils.mkdir(buff)
	rescue => exception
		puts(exception)
	else
		puts("mkdir Successful!")
	end
	puts()
	
	# for fails or success record
	failed_ff = File.open(File.join(buff, "failed_files"), "w")
	succ_ff = File.open(File.join(buff, "succ_files"), "w")
	
	# record, temps variables
	total_size = 0.0
	total_copied_files = 0
	total_ucopied_files = 0
	
	Dir::workify(directory) do |file_path|
		next if File.symlink?(file_path)
		total_size += File.size(file_path)
		
		if file_path.match(regx) then	
			puts("File Name: #{File.basename(file_path)}")
			puts("Source Path: #{File.dirname(File.absolute_path(file_path))}")
			begin 
				file_name = appr(File.basename(file_path), destination)
				puts("Dest Name: #{file_name}")
				FileUtils.copy(file_path, File.join(destination, file_name))
			rescue => exception
				puts("Copy Failed: #{exception}")
				total_ucopied_files += 1
				failed_ff.puts("#{[file_path, exception].to_s}")
				playic("z")
			else
				puts("Copy Successful!")
				total_copied_files += 1
				succ_ff.puts(file_path)
			end
			puts("Total size processed: #{(total_size/1024**2).round(3)} MB") 
			puts()
		end
	end
	failed_ff.close()
	succ_ff.close()
	
	puts("\nTotal size processed: #{(total_size/1024**3).round(3)} GB")
	puts("Total files copied: #{total_copied_files}")
	puts("Total failed attempts: #{total_ucopied_files}")

end


#~ cprFilex("/home/mash", "/media/mash/TheHemingwa/cprx_files", /^.*\.(png|jpg|JPEG|PNG|JPG|jpeg)$/)
#~ playic("zJzJz")

