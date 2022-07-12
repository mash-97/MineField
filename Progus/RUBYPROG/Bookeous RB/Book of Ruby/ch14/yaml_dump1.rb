# The Book of Ruby - http://www.sapphiresteel.com

require "yaml"

arr = ["fred", "bert", "mary"]			
yaml_arr = YAML.dump( arr )
puts( yaml_arr )
puts("vvvvvvv")
a = p( yaml_arr )    
puts("xxxxxxx")
puts("a = #{a}")
puts("vvvvvvv")
puts yaml_arr
