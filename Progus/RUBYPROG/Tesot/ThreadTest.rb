a = 10

Thread.new	{
	1000.times	{ 
		puts("in thread 1: #{a}")
		a += 1
	}
	puts("Inside Thread 1 :: a: #{a}")
}
puts("after thread 1: #{a}")

Thread.new 	{
	1000.times	{
		puts("in thread 2: #{a}")
		a += 1
	}
	puts("Inside Thread 2 :: a: #{a}")
}

puts("after thread 2: #{a}")
sleep(10)


#~ class A
	#~ def a
		#~ puts("this is a")
	#~ end
	
	#~ def b
		#~ puts("this is b")
		#~ self.a
	#~ end
	
	#~ def c
		#~ puts("this is c")
		#~ b()
	#~ end
#~ end

#~ a = A.new
#~ a.c
