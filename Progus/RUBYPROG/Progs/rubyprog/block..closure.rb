#block..closure.rb
x = "hello world"
ablock = Proc.new {puts(a)}

def aMethod(aBlockArg)
	x = "goodbye"
	aBlockArg.call
end

puts(x)
ablock.call
aMethod(ablock)
ablock.call
puts(x)

gets