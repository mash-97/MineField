							##include_enum1.rb##
class MyCollection
	include Enumerable
	
	def initialize(someItems)
		@items = someItems
	end
	
	def each
		@items.each{|i|
			puts("**")
			yield(i+1)
			p(yield(i+1))
		}
	end
end

things = MyCollection.new([3, 2, 1])

p(things.min{|a,b| a <=> b})
p(things.max{|a,b| a <=> b})
p(things.collect{|i| i.to_s.downcase})
gets