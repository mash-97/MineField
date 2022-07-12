require 'net/http'

url = URI.parse("http://www.rubyinside.com/test.cgi")

response = Net::HTTP.post_form(url, {'name' => 'David', 'age' => '24'})
puts response.body

Net::HTTP.start(url.host, url.port) do 
	|http|
	req = Net::HTTP::Post.new(url.path)
	req.set_form_data( {'name' => 'David', 'age' => '24'})
	puts(http.request(req).body)
end
