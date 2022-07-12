module Fibo

	$fibos = Array.new

	$fibos[0] = 0
	$fibos[1] = 1
	
	def fibo(n)
		if($fibos[n] != nil) then return $fibos[n] end
		
		$fibos[n] = fibo(n-1) + fibo(n-2)
		
		return $fibos[n]
	end
end

def f(n)
	a = (1+Math.sqrt(5))**n
	b = (1-Math.sqrt(5))**n
	c = 2**n * Math.sqrt(5)
	
	((a-b)/c).to_i
end

include Fibo
while(print("Order: ") == nil and (o=gets) != nil) do
	o = o.to_i
	
	s = Time.now
	f = fibo(o)
	e = Time.now
	
	puts("fibo(#{o}):  #{f}  ::  execution time: #{(e-s).to_f}")
	puts("f(#{o}): #{f(o)}")
	puts
end
	
		
	
