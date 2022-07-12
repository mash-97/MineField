require 'mysql2'

client = Mysql2::Client.new(host: "localhost", username: "tash", password: "tash")
puts(client)

print(client.query("show databases").to_a(as: :array).flatten)
puts
client.query("use javabook")
h = client.query("select * from Course")

h.each do 
	|row|
	puts("Course ID: #{row["courseId"]}, Title: #{row["title"]}")
end

client.close()
gets
