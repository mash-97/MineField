#! /usr/bin/ruby
puts("__ID__: #{__id__}")
puts("__FILE__: #{__FILE__}")
puts("PID: #{Process.pid}")
puts("UID: #{Process.uid}")
puts("GID: #{Process.gid}")

print("running test.rb: ")
child = fork do
	$result = exec("ruby test.rb")
end

Process.wait child
puts($result)
puts("Ended running test.rb")

