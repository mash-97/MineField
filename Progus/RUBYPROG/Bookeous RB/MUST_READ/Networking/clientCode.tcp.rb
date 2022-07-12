require "socket"

session = TCPSocket.new("localhost", 12321)

puts("The  time is #{session.gets.chomp}")

session.close
