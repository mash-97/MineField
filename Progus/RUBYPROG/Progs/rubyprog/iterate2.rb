class MyArray < Array
=begin	
	def initialize(anArray)
		super(anArray)
	end
=end
	def timesRepeat(aNum)
		aNum.times{|num|
			self.each{|anitem|
				yield("[#{num+1}]:: '#{anitem}'")
			}
		}
	end
end

array = MyArray.new(["hello", "good day", "how do you do"])
numarray = MyArray.new([1,2,3])
puts('arry.timesRepeat(3){|x|puts(x)}')
array.timesRepeat(3){|x|puts(x)}
puts('numarray.timesRepeat(3){|x|puts(x)}')
numarray.timesRepeat(2){|x|puts(x)}

gets