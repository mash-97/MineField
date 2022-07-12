require 'socket'

hostname = "localhost"
port = 2000

s = TCPSocket.open(hostname, port)

while message = s.gets do
	puts(eval(message))
end

s.close()
	
