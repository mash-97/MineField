def aMethod(doThis)
	if(doThis == :deletfiles) then
		puts("Now deleting files...")
	elsif(doThis == :formatdisk) then
		puts("Now formatting disk...")
	else
		puts("Sorry, command not understood.")
	end
end

def anotherMethod(doThis)
	case(doThis)
		when :deletfiles; puts("Now deleting files...")
		when :formatdisk; puts("Now formatting disk...")
		else puts("Sorry, command not understood.")
	end
end

aMethod(:deletfiles)
aMethod(:formatdisk)
aMethod(:eatlunch)

anotherMethod(:deletfiles)
anotherMethod(:formatdisk)
anotherMethod(:eatlunch)

gets