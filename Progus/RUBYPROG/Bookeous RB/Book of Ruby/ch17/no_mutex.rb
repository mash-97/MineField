# The Book of Ruby - http://www.sapphiresteel.com

$i = 0

a = Thread.new { 
	1000000.times{ $i = "a" }									
}
				 

b = Thread.new {				
	1000000.times{ $i = "b"}
} 
a.priority = -1
a.priority = -3
[a,b].each{|t|t.join}               

puts( $i )
