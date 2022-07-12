$hours_asleep = 0			#variables beginning with $ are global

def tired
	if $hours_asleep >= 8 then
		$hours_asleep = 0
		return false
	else
		$hours_asleep += 1
		return true
	end
end

def snore
	puts ('snore...')
end

def sleep
	puts("z"*$hours_asleep)
end

while tired do sleep end	#Single line while loop

puts("I'm wide awake and ready to face the day!")

while tired
	sleep
	snore
end							#Multi-line while loop

puts("I'm wide awake and ready to face a 2nd day!")


sleep while tired			#Single line while modifiers
puts("I'm wide awake and ready to face a 3rd day!")

begin
	sleep
	snore
end while tired
puts("I'm wide awake and ready to face a 4th day!")

=begin
	Below a method to prevent instant out at end of runtime.
	Because neither there will be a instant out call at last the end of run.
=end

gets