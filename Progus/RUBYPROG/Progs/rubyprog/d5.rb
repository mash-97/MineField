localvar="Hello"
$globalvar="goodbye"

puts ("#{localvar} & #{$globalvar})")

def amethod
	localvar = 10
	puts(localvar)
	puts(localvar)
end

def anotherMethod
	localvar = 500
	$globalvar = "bonjour"
	puts(localvar)
	puts($globalvar)
end

amethod
anotherMethod

puts($globalvar)
puts(localvar)

