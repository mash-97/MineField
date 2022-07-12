require 'set'

#~ pr = Proc.new{|e| puts("#{e}, #{e.class}")}

#~ h = {:hello => "hello", :goodbye => "goodbye", :yo => "yo"}

#~ s = h.to_set
#~ puts s.class

#~ s.each{|e| pr.call(e)}


#~ a = h.to_a
#~ puts a.class

#~ a.each{|e| pr.call(e)}


#~ array = [1,2,3,3,3]

#~ s = array.to_set

#~ for i in (0...s.length) do puts s.get(i) end


class Alg
	attr_accessor :a, :b
	def initialize(a, b)
		@a = a
		@b = b
	end
	
	def div; @a/@b; end
	
	def add; @a+@b; end
	
	def min; @a-@b; end
	
	def mul; @a*@b; end

end

def Alg.set_ab(object)
		puts(self)
		print("a = ")
		object.a = gets.to_i
		print("b = ")
		object.b = gets.to_i
		puts
	end
	
#~ a = Alg.new(2,3)
#~ Alg.set_ab(a)

#~ 10.times do
	#~ print("Enter operation name: ")
	#~ opn = gets.chomp.to_sym
	#~ if a.public_methods.include?(opn) then
		#~ puts("Result for #{opn} on #{a} is #{a.send(opn)}")
	#~ else
		#~ puts("Operation #{opn} not found")
	#~ end
	#~ puts
#~ end


#~ def blocka(b)
	#~ puts b.class
#~ end

#~ blocka proc{puts "yo"}

#~ require 'active_record'

#~ class Order < ActiveRecord::Base
	#~ has_many :line_items

	#~ def self.find_all_unpaid
		#~ puts("finding all unpaid")
		#~ puts(self)
		#~ self.where('paid = 0')
	#~ end
	#~ puts(self)
	#~ find_all_unpaid
	#~ def total
		#~ puts(self)
		#~ sum = 0
		#~ line_items.each do
			#~ |item| 
			#~ sum += item.price
		#~ end
		#~ return sum
	#~ end
#~ end

require 'mashz'


