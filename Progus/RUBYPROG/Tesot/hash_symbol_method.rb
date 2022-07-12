def disp(a)
	if(a.class != Hash) then puts("Undefined method calling!") end
	
	if(a[:a]==nil) then puts("You didn't provided :a")
	elsif(a[:a] == nil and a[:b]==nil) then puts("Even not :b")
	else
		puts a
	end
end

#~ a = { 
	#~ :a => "a",
	#~ :b => "b",
	#~ :c => "c",
	#~ }
#~ puts("outside the disp:", a)
puts("inside the disp:")
disp(a: "b")
puts
puts
puts
