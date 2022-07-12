#! /usr/bin/ruby

def tim(times)
	thread = Thread.new do
		yield()
	end
	return false unless thread.join(times)
	return true
end
require 'rubygems'
require 'inline'
require 'benchmark'

class Integer
	def fac
		(1..self).inject{|x,y| x*y}
	end
end

class CF
	inline do |builder|
		builder.c %q{
			long long fac(int number)
			{
				long long int result = 1;
				while(number>=2) 
				{
					result *= (long long int)(number);
					--number;
				}
				return result;
			}
		}
	end
end
				
Benchmark.bm do
	|bmm|
	bmm.report("ruby: ") do
		100000.times do 10.fac() end
	end
	
	bmm.report("c: ") do
		c = CF.new
		100000.times do c.fac(10) end
	end
end


