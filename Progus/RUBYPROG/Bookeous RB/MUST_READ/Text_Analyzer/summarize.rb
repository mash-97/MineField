
text = %q{
	Ruby is a great programming language. It is a object oriented and has many groovy features.
	Some people don't like it, but that is not our problem! It's easy to learn. It's great.
	If you want to know more about ruby, visit the official web site of ruby.
}

sentences = text.gsub(/\s+/, ' ').strip.split(/\.|\?|!/).collect{|x| x.strip}
sentences_sorted = sentences.sort_by(&:length)

one_third = sentences_sorted.length/3
ideal_sentences = sentences_sorted.slice(one_third, one_third+1)

l = ->(x){x =~ /is|are/}

ideal_sentences.select!(&l)

p ideal_sentences.join(". ")

