require "net/https"

URL = "https://www.random.org/integers/"

def get_random_numbers(count=1, min=0, max=99)
	uri = URI.parse(URL)
	puts("uri {URI.parse(#{URL})}: #{uri} => #{uri.class}")
	
	uri.query = URI.encode_www_form(col: 1, base: 10, format: "plain", rnd: "new", num: count, min: min, max: max)
	puts("uri.query: #{uri.query} => #{uri.query.class}")
	
	response = Net::HTTP.get_response(uri)
	puts("response: #{response} => #{response.class}")
	case(response)
	when Net::HTTPOK
		res = response.body.lines.map(&:to_i)
		puts("res: #{res} => #{res.class}")
	else
		res = []
	end
	return res
end

puts(get_random_numbers(5, 1, 100))
