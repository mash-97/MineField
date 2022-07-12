#~ require_relative 'A.rb'
#~ puts File.expand_path File.dirname(__FILE__)

#~ A.new

#~ class Array
	#~ def subsets
		#~ subsets = []
		#~ for b in 0...(1 << self.size) do
			#~ subset = []
			#~ self.size.times {|i|
				#~ subset << self[i] if b[i] == 1
			#~ }
			#~ subsets << subset
		#~ end
		#~ subsets
	#~ end
	
	#~ def subarray_sum(number)
		#~ self.subsets.map{|x| x if x.sum==number}.compact
	#~ end
		
#~ end


#~ array = [1,3,2,5,1,1,2,3]

#~ times = []
#~ total = 1000000
#~ total.times{
	#~ s = Time.now
	#~ res = array.subarray_sum(8)
	#~ e = Time.now
	#~ time = ((e-s)*10**6).round(2)
	#~ #puts("time: #{time} micro seconds")
	#~ times << time
#~ }
#~ puts("Average: #{(times.sum/times.size.to_f).round(2)}")


class A
	def initialize
		@@total_A_objects += 1
	end
	
	public
	def pubm
		puts("A:: public  method :pubm  :: #{self}")
		puts(":pubm Calling private method :privm :: ")
		privm()
		puts(":pubm Calling protected method :protm :: ")
		protm()
		puts
	end
	
	def +(object_A)
	end
		
	
	private
	def privm
		puts("A:: private method :privm  :: #{self}")
		puts
		
	end
	
	protected 
	def protm
		puts("A:: protected method :protm  :: #{self}")
		puts
		puts(":protm Calling private method :privm :: #{self}")
		privm()
		puts
	end
end

PI = 2.233

module Am
	PI = 1.233
end
puts __FILE__

puts `echo $(#{"ls"})`
