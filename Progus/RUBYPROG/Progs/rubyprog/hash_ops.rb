h1 = {
		'key1' => 'value1',
		'key2' => 'value2',
		'key3' => 'value3',
		'key4' => 'value4'
	}

h2 = {
		'key1' 	  => 'value1',
		'KEY_TWO' => 'value2',
		'key3'	  => 'VALUE_3',
		'key4'	  => 'value4'
	}
	
p(h1.keys & h2.keys)
p(h1.values & h2.values)
p(h1.keys + h2.keys)
p(h1.values - h2.values)

p(h1.keys << h2.keys)

p((h1.keys << h2.keys).flatten.reverse)

gets