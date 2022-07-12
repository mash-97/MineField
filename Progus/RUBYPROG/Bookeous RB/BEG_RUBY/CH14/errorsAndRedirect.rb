require 'net/http'

def get_web_document(url)
	uri = URI.parse(url)
	res = Net::HTTP.get_response(uri)
	
	case(res)
		when Net::HTTPOK
			return(res.body)
		when Net::HTTPRedirection
			puts("res: #{res} => #{res.class}")
			#puts("res.methods: #{res.methods}")
			puts("res.response: #{res.response}")
			return get_web_document(res['Location'])
		else
			return "Page not Found!"
	end
end


puts get_web_document("http://www.rubyinside.com/test.txt")
puts get_web_document("http://www.rubyinside.com/non-existent")
puts get_web_document("http://www.rubyinside.com/redirect-test")
