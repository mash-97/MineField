require 'webrick'

class MyNormalClass
	def self.add(a,b)
		a.to_i + b.to_i
	end
	
	def self.sub(a,b)
		a.to_i - b.to_i
	end
end

class MyServlet < WEBrick::HTTPServlet::AbstractServlet
	def do_GET(request, response)
		if request.query['a'] and request.query['b'] then
			a = request.query['a']
			b = request.query['b']
			response.status = 200
			response.content_type = 'text/plain'
			result = nil
		
			case request.path
				when '/add'
					result = MyNormalClass.add(a,b)
				
				when '/sub'
					result = MyNormalClass.sub(a,b)
				
				else
					result = "No Such Method"
			end
			
			response.body = result.to_s + "\n"
		
		else 
			response.status = 400
			response.body = "You did not provide correct parameters!"
		end
	end
end


server = WEBrick::HTTPServer.new(:Port => 1234)
server.mount("/", MyServlet)

trap("INT") do server.shutdown() end

server.start()

