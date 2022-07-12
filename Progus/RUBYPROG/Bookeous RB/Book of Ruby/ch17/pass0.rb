# The Book of Ruby - http://www.sapphiresteel.com

a = Thread.new { Thread.stop
					print "a"; Thread.pass;
				 ("b".."h").each{|x| print(x)}
			 }
b = Thread.new {
				 Thread.stop
				 print "x"; Thread.pass;
                 print "y"; Thread.pass;
				 print "z" 
			}

a.priority = -3
b.priority = -1

a.run
b.run
		 
a.join

