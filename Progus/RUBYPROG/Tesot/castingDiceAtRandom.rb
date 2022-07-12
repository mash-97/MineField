
require 'net/https'

URL = "https://www.random.org/integers/"

def get_random_numbers(count = 1, min = 0, max = 99)
 uri = URI.parse(URL)
 uri.query = URI.encode_www_form(col: 1, base: 10, format: "plain", rnd: "new", num: count, min: min, max: max)
 response = Net::HTTP.get_response(uri)
 
 case(response)
	when Net::HTTPOK
		response.body.lines.map(&:to_i)
	else
		[]
	end
end

print(get_random_numbers(5, 1, 6))
