module One
	class Fred
	end
	$f1 = :Fred
end

module Two
	Fred = 1
	$f2 = :Fred
end

def Fred()
	ff = :Fred
	puts(ff.object_id)
end

$f3 = :Fred
puts("Id of $f1, $f2, $f3: ")
puts($f1.object_id)
puts($f2.object_id)
puts($f3.object_id)
Fred()
gets