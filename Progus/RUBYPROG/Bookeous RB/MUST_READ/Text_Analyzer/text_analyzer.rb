# loading the file 
file = File.open("text.txt")

# reading the lines from the file
r = File.readlines(file)

# join the array of strings
string = r.join

# counting total characters
tc = string.length

# counting total characters excluding spaces
tc_exs = string.scan(/\S/).length

# counting total words
tw = string.split.length

# counting total sentences
ts = string.split(/[.?!]/).length

# counting total paragraphs
tp = string.split(/\n\n/).length

# average words per sentences
av_wps = tw.to_f/ts.to_f

# average sentences per paragraphs
av_spp = ts.to_f/tp.to_f

puts string
puts
puts
puts("Total Lines: #{r.length}")
puts("Total Characters: #{tc}")
puts("Total Characters excluding spaces: #{tc_exs}")
puts("Total Words: #{tw}")
puts("Total Sentences: #{ts}")
puts("Total Paragraph: #{tp}")

puts("Average Words Per Sentence: #{av_wps.round}")
puts("Average Sentences Per Paragraph: #{av_spp.round}")
puts
puts


# defining stop words
stop_words = %w{the a by my is I has had have some that this on of for}
stopwords = %w{the a by on for of are with just but and to the my I has some in}

words = string.scan(/\w+/)
words_wsw = words.reject{|x| stopwords.include?(x)}
fluffp = (words_wsw.length.to_f/words.length.to_f*100).to_i

puts("Non-Fluff Words: #{fluffp}%")
