#!/usr/bin/ruby

status = `git status`
if status =~ /nothing to commit/ then
  puts(status)
else
  puts `git add .`
  puts `git commit -m #{Time.now.to_i}`
end
