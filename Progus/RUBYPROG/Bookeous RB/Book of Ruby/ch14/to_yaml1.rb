# The Book of Ruby - http://www.sapphiresteel.com

require 'yaml'

puts( "hello world".to_yaml )
puts( 123.to_yaml )
puts( ["a1", "a2" ].to_yaml )
puts( {:h1 => 1, :h2 => 2}.to_yaml )
puts({:b1 => {:c => 1, :d => 2}, :b2 => 3}.to_yaml)
puts(["2", "3", "4"].to_yaml)
puts(2334.to_yaml)
