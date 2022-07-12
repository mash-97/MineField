require "socket"

server = UDPSocket.open		# Using UDP here...
server.bind(nil, 3000)

loop do
t, sender = server.recvfrom(0)
puts("#{t} => #{t.class} and #{sender} => #{sender.class}")
server.send("#{Time.now}\n", 1, sender[3], sender[1])
end


