file_name = "regexp1.rb"

IO.foreach(file_name){
	|l|
	if(/^.*#(.*)/ =~ l) then puts $1 end
}


