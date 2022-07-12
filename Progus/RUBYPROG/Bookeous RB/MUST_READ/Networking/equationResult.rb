require "net/https"

URL = "https://www.calculatorsoup.com/calculators/math/adding-and-subtracting-integers-calculator.php"


def get_result(expression)
	uri = URI.parse(URL)
	uri.query = URI.encode_www_form(x: expression, action: "Calculate")
	
	response = Net::HTTP.get_response(uri)
	
	case response
		when Net::HTTPOK
			response.body.lines
		else
			return false
	end
end

puts(get_result("3+3"))
