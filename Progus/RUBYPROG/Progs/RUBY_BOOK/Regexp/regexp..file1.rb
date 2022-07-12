#create new file with c-style line comments
File.open('testfile1.txt', 'w'){
	|f|
	File.foreach('regexp1.rb'){
		|line|
		f.puts(line.sub(/(^\s*)(.*)#(.*)/, '\1//\2'))
	}
}

puts("Done")
