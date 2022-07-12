x = /#/.match( "def myMethod # This is a very nice method")
puts(x.pre_match)
puts($`)
puts(x.post_match)
puts($')

