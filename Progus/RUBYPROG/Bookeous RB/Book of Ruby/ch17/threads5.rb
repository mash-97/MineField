# The Book of Ruby - http://www.sapphiresteel.com

startTime = Time.new
puts( "Start: %10.5f" % startTime )

t1 = Thread.new{ 
	0.upto(3) {print( "t1\n" )}	
}

t2 = Thread.new{ 
	0.upto(3) {print( "t2\n" )}
}

t3 = Thread.new{ 
	0.upto(3) {print( "t3\n" )}
}

#set main thread to have a high priority
Thread.main.priority = 200
t1.priority = 0
t2.priority = 1
t3.priority = 5


[t1,t2,t3].each{ |t| t.join } 

endTime = Time.new
puts( "End: %10.5f" % endTime.to_f )
totalTime = endTime-startTime
puts( "Total Time: %10.5f" % totalTime.to_f )
puts( Thread.main.priority )
