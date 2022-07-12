#5blocks.rb
def abc(a,b,c)
	puts("--abc---")
	a.call
	b.call
	c.call
	yield
end

def abc2(&d)
	puts('---abc2---')
	d.call
end

def abc3(a,b,c, &d)
	puts("---abc3---")
	a.call
	b.call
	c.call
	d.call
	yield
end

def xyz
	puts('---xyz---')
	x = 1
	y = 2
	z = 3
	yield(x,y,z)
end

a = lambda{puts"one"}
b = lambda{puts"two"}
c = proc{puts"three"}
myproc = proc{puts("my proc")}

abc(a,b,c){puts"four"}
abc2{puts"four"}
#abc2(10)#<This is an error!
abc3(a,b,c){puts"five"}
abc3(a,b,c,&myproc)
puts("###")
xyz(&myproc)
puts('333')
xyz{|a,b,c| puts(a+b+c)}
puts(a,b,c)

puts("EEEEE")
abc3(a,b,c,&myproc)
abc3(a,b,c){puts"Yo"}
gets