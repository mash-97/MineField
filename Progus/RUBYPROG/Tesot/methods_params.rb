require 'yaml'
def m(a)
	puts("class: #{a.class} and value: #{a}")
end

m(h: 'h', 'g' => {g: 3, h: 4})
