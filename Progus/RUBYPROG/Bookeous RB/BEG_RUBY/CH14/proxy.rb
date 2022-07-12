require 'net/http'


http_class = ARGV.first ? Net::HTTP::Proxy : Net::HTTP
url = URI.parse('http://www.rubyinside.com/test.txt')

response = http_class.get_response(url)
puts response.body
