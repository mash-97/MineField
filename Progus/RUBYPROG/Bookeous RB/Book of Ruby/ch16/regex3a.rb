# The Book of Ruby - http://www.sapphiresteel.com

# print only comments
IO.foreach( 'regex1.rb' ){ |line|	
	if line =~ /^*#/ then
		puts( line )
	end
}


