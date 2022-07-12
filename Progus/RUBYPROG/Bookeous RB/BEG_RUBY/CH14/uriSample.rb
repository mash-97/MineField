require 'net/http'

url = URI.parse("http://www.rubyinside.com/test.txt")

puts("url.host: #{url.host} :: url.port: #{url.port} :: url.path: #{url.path}")
Net::HTTP.start(url.host, url.port) do 
	|http|
	req = Net::HTTP::Get.new(url.path)
	puts(http.request(req).body)
end

puts
url = URI.parse("http://www.rubyinside.com/test.txt")
response = Net::HTTP.get_response(url)
puts(response.body)

puts
puts






url = URI.parse("https://www.urionlinejudge.com.br/judge/en/problems/index/1?page=5")
response = Net::HTTP.get_response(url)
puts(response.body)
puts
puts
puts("response: #{response} => #{response.class}")
if(response.class.to_s == String.to_s) then 
	puts("length: #{response.length}")
end
puts("response.body => #{response.body.class} and length: #{response.body.length}")
