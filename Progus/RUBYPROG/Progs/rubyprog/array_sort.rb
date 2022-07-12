document = <<Yossup
	You can pass a block to the sort method of array to determine how two consecutive elements are sorted.
Here we convert each element, a and b to a string so that nil can be sorted.
Since nil.to_s returns an empty string, nil will always be sorted 'low'.

Yossup

array = ['h', 'e', 'l', 'l', 'o', ' ' , nil, 'w', 'o', 'r', 'l', 'd', nil, 1, 2, 3, nil, 5, 4]

#sort ascending from nil upwards

sorted_array = array.sort{
	|a, b|
	a.to_s <=> b.to_s
}

#Sort descending from upper value down to nil

reversed_sorted_array = array.sort{
	|a, b|
	b.to_s <=> a.to_s
}


p(array)
p(sorted_array)
p(reversed_sorted_array)

gets
