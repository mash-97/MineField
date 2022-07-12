#~ puts("File path: #{File.dirname(__FILE__)}")
#~ puts("Inside test_1.rb")

#~ `gnome-terminal --window -- ruby ./logTest.rb`
#~ `gnome-terminal --window -- ruby ./mysqldb.rb`


#~ require 'memoize'
#~ require 'benchmark'

#~ include Memoize

#~ def fib(n)
	#~ return n if n<2
	#~ return fib(n-1)+fib(n-2)
#~ end

#~ Benchmark.bm(35) do |b|
	#~ b.report("Normal Fib: "){fib(35)}
	#~ b.report("Memoize Fib: "){memoize(:fib); fib(35)}
#~ end

def fib(n)
	n < 2 ? n : fib(n-1)+fib(n-2)
end


#~ def memoize(method)
	#~ cache = {}
	#~ lambda = ->(args){
		#~ if cache.include?(args) then return cache[args]
		#~ else
			#~ cache[args] = method(method).call(args)
			#~ return cache[args]
		#~ end
	#~ }
	#~ return lambda
	
#~ end

#~ a = memoize(:fib)
#~ puts a
#~ puts a.call(63)


#~ def check(a)
	#~ x = 0
	#~ while(x<a.length-1) do
		#~ return false if a[x].to_s=~/a/ && a[x+1].to_s=~/a/
		#~ x += 1
	#~ end
	#~ return true
#~ end

#~ a = [:a1, :a2]
#~ b = (1..4).collect{|x| "b#{x}".to_sym}
#~ ab = a+b

#~ pab = []
#~ ab.permutation{|x| pab<<x if check(x)}

#~ puts pab.size
#~ pab.each{|x| p(x) if not check(x)}

#~ require 'mash'
#~ class Integer
	#~ alias ! facto
#~ end

#~ def om(n)
	#~ ((2*n-1).!)/(2**(n-1)*(n-1).!)
#~ end

#~ def oom(n)
	#~ (1..(2*n-1)).select(&:odd?).inject(&:*)
#~ end

#~ puts oom 5
#~ puts om(5)



#~ a = "daughter".split(//)
#~ p = []
#~ a.permutation(8){|x|
	#~ p << x if not (x.join=~/^.*[aeu]{3}.*$/)
#~ }

#~ puts p.size
#~ p p
#~ puts __FILE__

#~ f = File.new('./test_2.rb', 'w')
#~ r = File.readlines(__FILE__)
#~ r.each{|x| f.puts(x)}
#~ f.close

#~ `echo $( gnome-terminal --window -- ruby ./test_2.rb)`


def countns(a, b, n)
	count = 0
	a,b = b,a if a > b
	if a%n==0 then
		count += ((b-a)/n)+1
	else
		if b%n==0 then
			count += ((b-a)/n)+1
		else
			count += (b-a+(n-2))/n
		end
	end
	return count
end

def countns1(a, b, n)
	count = 0
	a,b, = b,a if a>b
	a = a+(n-(a%n)) if a%n!=0
	while(a<=b) do
		count+=1
		a+=n
	end
	return count
end

def countns2(a, b, n)
	a = a+(n-(a%n)) if a%n!=0
	a,b = b,a if a>b
	return ((b-a)/n) + 1
end

def countns3(a, b, n)
	return ((b-a)/n) + 1
end

#~ inputs = File.readlines("./input.txt")
#~ inputs.each do
	#~ |input|
	#~ a,b,n = input.chomp.split(' ').map(&:to_i)
	#~ puts("#{a} #{b} #{n}")
	#~ ar = []
	#~ ar<<countns(a,b,n)
	#~ ar<<countns1(a,b,n)
	#~ ar<<countns2(a,b,n)
	#~ ar<<countns3(a,b,n)
	#~ puts("#{ar}")
	#~ if not ar.inject{|x,y| if x==y then x else false end} then puts("Full matching failed!!!") end
	
#~ end

require 'inline'
Object.inline do |builder|
	builder.c 'void yoh(){printf("YOH");}'
end

yoh()
