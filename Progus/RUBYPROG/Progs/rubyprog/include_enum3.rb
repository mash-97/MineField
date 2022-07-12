								##include_enum3.rb##
class MyCollection
	include Enumerable
	def initialize(sometimes)
		@items = sometimes
	end
	
	def each
		@items.each{|i| yield i}
	end
	
	def min
		@items.to_a.min{|a,b| a.length <=> b.length}
	end
	
	def max 
		@items.to_a.max{|a,b| a.length <=> b.length}
	end
end
things = MyCollection.new(['a', 'b', 'cd'])
h = {
		'one' => 'for joy',
		'two' => 'for girl',
		'three' => 'for hug'
	}

h_keys = MyCollection.new(h.keys)
h_values = MyCollection.new(h.values)

puts("======things=======")

x = things.collect{|i| i}
p x

y = things.max
p y

z = things.min
p z

p(things.include?('def'))	
p(things.include?('xy'))


puts('=======h_keys ========')
x = h_keys.collect{|i| i}
p x 

y = h_keys.max
p y 

z = h_keys.min
p z

p(h_keys.include?('two'))
p(h_keys.include?('twenty'))

p("========h_values========")
x = h_values.collect{|i| i}
p x 
 
y = h_values.max
p y 

z = h_values.min
p z

p(h_values.include?('for joy'))
p(h_values.include?('3'))

gets