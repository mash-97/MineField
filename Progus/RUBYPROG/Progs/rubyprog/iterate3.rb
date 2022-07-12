multiarray = [['one', 'two', 'three', 'four'],
			  [1,2,3,4],
			  [:a,:b,:c,:d]
			 ]
#compare with iteration techniques in multi_array.rb(ch4)

#works with any number of items but a fixed number (2) of arrays
puts('========1=========')
multiarray[0].length.times{|i|
	puts(multiarray[0][i], multiarray[1][i])
}

#iterate through all the arrays, printing each array item in sequence
#workds with any number of arrays and any number of items
puts('=======2=======')
multiarray.each{|array|
	multiarray[0].length.times{|i|
		puts(array[i])
	}
	
	
}

#iterate through each item index, printing the item at that index from each array
#works with any number of arrays and any number of items
puts('========3=======')
multiarray[0].length.times{|i|	
	multiarray.each{|array|	
		puts(array[i])
	}
}

gets
gets