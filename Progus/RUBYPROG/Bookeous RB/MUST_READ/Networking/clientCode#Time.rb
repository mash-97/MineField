require "socket"
require "timeout"

socket = UDPSocket.new
socket.connect("localhost", 3000)

socket.send("", 0)
Timeout.timeout(10) do
	time = socket.gets
	puts("This time is #{time}")
end
