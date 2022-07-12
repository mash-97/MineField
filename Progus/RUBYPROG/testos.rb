
#~ require 'mathn'

#~ def c(n)
	#~ c = 0
	#~ s = Time.now
	#~ (1..n).each{|x| c+=1 if x.prime?}
	#~ e = Time.now
	
	#~ return [c, (e-s).to_f]
#~ end

#~ loop do
	#~ print(">>> ")
	#~ n = gets
	#~ n = n.to_i if n!=nil
	#~ break if n==0 || n==nil
	
	#~ r = c(n)
	#~ print(r)
	#~ puts
	#~ puts
#~ end

#~ def sieve(number)
	#~ mark = Array.new(number, true)
	#~ primes = [2]
	
	#~ mark[0] = false;
	#~ mark[1] = false;
	
	#~ i = 4
	#~ while(i<=number) do 
		#~ mark[i] = false
		#~ i += 2
	#~ end
	
	#~ i = 3
	#~ while(i<=number) do
		#~ if(mark[i]) then
			#~ primes << i 
			#~ j = i*i
			#~ while(j<=number) do 
				#~ mark[j] = false
				#~ j += i*2
			#~ end
		#~ end
		#~ i+=2
	#~ end
	
	#~ return [mark, primes]
#~ end

#~ results = sieve(99999999)
#~ primes = results[1]
#~ marks = results[0]

#~ puts(primes.index(2))
#~ puts(primes.index(547))
#~ puts(primes.index(1229))
#~ puts(primes.index(99995257))
#~ puts(primes.index(99996931))
#~ puts(primes.index(99998953))
#~ gets
#~ gets

#~ gems = `gem list`.split(/\n/).collect{|x| x.split(' ')[0]}

#~ r_hash = {:false => [], :true => []}
#~ loaded_error = 0

#~ gems.each{|x|
	#~ print("For #{x}: ")
	#~ r = false
	#~ begin
		#~ r = require(x)
	#~ rescue Exception => e
		#~ puts(e.class)
		#~ puts(e)
		#~ loaded_error += 1
	#~ ensure
		#~ puts(r)
	#~ end
	
	#~ r_hash[r.to_s.to_sym]<< x
	#~ puts
#~ }


#~ puts("------------------------------------------------")
#~ puts("------------------------------------------------")
#~ puts("Failed Loads: #{r_hash[:false].length}")
#~ puts("------------------------------------------------")
#~ r_hash[:false].each{|x| puts x}
#~ puts
#~ puts
#~ puts("------------------------------------------------")
#~ puts("------------------------------------------------")
#~ puts("Successful Loads: #{r_hash[:true].length}")
#~ puts("------------------------------------------------")
#~ r_hash[:true].each{|x| puts x}

#~ puts("------------------------------------------------")
#~ puts("------------------------------------------------")
#~ puts("Loaded Errors: #{loaded_error}")
#~ puts("------------------------------------------------")

def dispi(a)
	c = 1
	a.each{|x|
		puts("##{c}: #{x}")
		c+=1
	}
end

def File.match?(a,b)
	begin
		aa = File.binread(a)
		bb = File.binread(b)
		
		return aa == bb
	rescue Exception=> e
		puts(e)
	end
	false
end


#~ a = File.readlines(File.dirname(__FILE__)+'/chat.txt')
#~ dispi(a)
#~ puts
#~ c = 0
#~ a.each{|x|
	#~ c+=1
	#~ puts("##{c}: #{x}") if x=~/(M|m)ahim/ or x=~/(M|m)ashiur/ or x=~/(V|v)aia/
#~ }
#~ puts

def test(dir)
	Dir.foreach(dir){|f|
		if not (f=='.' or f=='..') then
			$a={} if $a==nil
			$a[f] = File.size(dir+"/"+f)
		end
	}
	return $test
end

def randoms(range, array_length)
	randoms = []
	array_length.times do 
		randoms << rand(range)
	end
	return randoms
end

require_relative("cprogram_generator.rb")
def modCost(array)
	return nil if array.length == 0
	cost = array[0]
	(1...array.length).each{ |index|
		cost = cost % array[index]
	}
	return cost
end

def maximumCost(array)
	result_array = []
	maximum_cost = -(1/0.0)
	array.sort!
	array.permutation{|x|
		cost = modCost(x)
		if(cost>maximum_cost) then
			maximum_cost = cost 
			result_array = x
		end
	}
	return {:max_cost => maximum_cost, :array => result_array}
end





require 'prime'

class MaxSumPrime
	attr_accessor :nsum_hash, :primes, :temp, :max
	def initialize(range)
		@max = range.max()
		@primes = range.select(&:prime?)
		@nsum_hash = {}
		@temp = []
	end
	
	def maxNP(number)
		return [number, [number]] if number==2 || number==3
		return nil if number < 2
		result = [0,[]]
		
		i = 0
		while i<max do
			puts("number: #{number}, @primes[#{i}]: #{@primes[i]}")
			temp = maxNP(number - @primes[i])
			if(temp == nil) then
				i += 1
				next
			end
			number -= @primes[i]
			result[1] << @primes[i]
			result[0] += temp[0]+1
			result[1] += temp[1]
		end
		
		return result
	end
		
	def forNumber(number)
		return nsum_hash[number] if(nsum_hash[number]!=nil)
		sum = 0
		count = 0
		elements_array = []
		
		for p in @primes do
			flag = true
			while(flag) do
				sum += p
				count += 1
			end
		end
	end
end


class File
	def self.mash_bytes(file_name)
		bytes = []
		f = File.open(file_name, 'rb')
		f.each_byte{|byte| bytes << byte}
		return bytes
	end
end


def unzip(file_name, destination)
	print("require 'zip': ")
	puts( require 'zip' )
	print("require 'fileutils': ")
	puts( require 'fileutils' )
	
	puts("Called for the file_name: #{file_name}")
	
	FileUtils.mkdir(destinaion) unless Dir.exists?(destination)
	
	begin 
		Zip::File.new(file_name) do |zip_file|
			zip_file.each do |file|
				print("For file: #{file} :: ")
				fp = File.join(destination, file)
				puts( zip_file.extract(file, fp))
			end
		end
	rescue Exception => exception
		puts("Failed to extract:: file_name: #{file_name}")
		puts("Related Exception:: #{exception}")
	end
	
end

class Class
	def add_accessor(accessor_name)
		#~ puts("Class:-:add_accessor: #{self} :: id: #{self.object_id}")
		#~ puts(self.instance_methods)
		self.class_eval %{
			attr_accessor :#{accessor_name}
		}
	end
end


class A
	def aa(an)
		puts("A:-:aa: #{self} :: id: #{self.object_id}")
	end
	
	puts("A: #{self}")
	def self.a
		puts("A::a: #{self} :: id: #{self.object_id}")
	end
		
end

class B < A
end

a = A.new
puts("a: #{a.object_id}")
a.aa(nil)
A.a()

a.add_accessor(:d)
