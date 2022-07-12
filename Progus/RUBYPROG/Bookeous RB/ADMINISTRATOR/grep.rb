a = ''
IO.foreach("./grep.test"){|l| a += l}
puts a =~ /tt/
