#Fizz and Buzz also FizzBuzz
l=0
for i in 1..100 do
	if i%3==0 then 
		puts "Fizz 0--->#{i}"
	elsif i%5==0 then 
	 puts "Buzz 0--->#{i}"
	end
	if i%3==0 && i%5==0 then
		l=i-l
		puts"FizzBuzz 0--->#{i}...act #{i/3} and #{i/5}, defend #{l}"
		f=File.new("Fibuz.txt", "w")
		f.puts("#{i%3}")
		f.close
	end
end		

j = gets