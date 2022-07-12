def plur(n)
	's' if n > 1
end

lines = File.readlines("txt.txt")
lines_count = lines.count
text = lines.join

puts "#{lines.count} line#{plur(lines_count)}"
puts text.length
puts text.count("\n")


character_exspaces = text.gsub(/\s/, '').length
puts "Total #{character_exspaces} character#{plur(character_exspaces)} without spaces"

character_exspaces = 0
text.scan(/\S/){ character_exspaces += 1}
puts "Total #{character_exspaces} character#{plur(character_exspaces)} without spaces"
