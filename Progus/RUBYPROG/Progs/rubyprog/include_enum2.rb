							##include_enum2.rb##
class MyCollection
	include Enumerable
	
	def initialize(someItems)
		@items = someItems
	end
	
	def each
		@items.each{|i|
			yield(i)
		}
	end
end

things = MyCollection.new(['one', 'two', 'three'])

h = {
		'one' => 'for sorrow',
		'two' => 'for joy',
		'three' => 'for a girl'
	}

h_keys = MyCollection.new(h.keys)
h_values = MyCollection.new(h.values)

puts('=============things===============')
x = h_keys.collect{|i| i}
p(x)

y = h_keys.max
p(y)

z = h_keys.min
p(z)

p(h_keys.include?("two"))

p(h_keys.include?("twenty"))

puts('============= h_values ==============')
x = h_values.collect{|i| i}
p x

y = h_values.max
p y

z = h_values.min
p z

p(h_values.include?('for joy'))
p(h_values.include?('for misery'))

gets