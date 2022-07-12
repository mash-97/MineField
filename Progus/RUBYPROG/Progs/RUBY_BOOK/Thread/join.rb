words = ['dork', 'fossing', 'lita', 'hilda']
numbers = [2, 4 ,5, 6]

Thread.new{
	words.each{|word| puts word}
}.join

Thread.new{
	numbers.each{|number| puts number}
}.join


