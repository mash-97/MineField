# The Book of Ruby - http://www.sapphiresteel.com

# This fails

ob = Object.new

# singleton class
class << ob
	def xxx( aStr )
		@x = aStr
	end	
	
	def marshal_dump
		[@x]
	end
	
	def marshal_load(data)
		@x = data[0]
	end
end

ob.xxx( "hello" )
p( ob )

File.open( 'test.sav', 'w' ){ |f|	
    Marshal.dump( ob, f )
}

File.open( 'test.sav' ){ |f|	
    ob = Marshal.load(f)
}


p( ob )

=begin
You can't tell us nothing.
Hard-headed and we're stubborn.
So, one ear and out the other.
When we're young
We're on the run of our lives.

Who knows what the future for us could hold.
Another shooter. Uh oh.
No more tomorrow's. We're done.
And all we are is
=end
