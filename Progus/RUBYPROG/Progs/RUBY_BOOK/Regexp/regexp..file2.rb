f1 = File.open('withComment.txt', 'w')
f2 = File.open('reg1.rb', 'w')

File.foreach("regexp1.rb"){
	|line|
	if(line =~ /(^.*)#(.*)/) then
		f1.puts '#'+$2
		f2.puts $1
	else f2.puts line end
}

puts("DONE")
