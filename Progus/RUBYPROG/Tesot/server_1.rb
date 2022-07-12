
require 'socket'

server = TCPServer.open(2000)

loop do
	client = server.accept()
	puts("for client: #{client}")
	puts("avilable methods for client: #{client.methods.to_s}")
	puts("client.addr: #{client.addr}")
	loop do
		print("evaluable message (e to exit): ")
		message = gets.chomp
		break if(message=='e')
		client.puts(message)
	end
	client.close()
end
