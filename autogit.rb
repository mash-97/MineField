#!/usr/bin/ruby

puts `git add .`
puts `git commit -m #{Time.now.to_i}`
