
def distinct_letters(string)
  letters = Array.new(26){nil}
  string.each_char{|c| letters[c.ord-'a'.ord]=true}
  letters.each_with_index.collect{|l, i| l==true ? ('a'.ord+i).chr : nil}.compact
end

def symmetric_dict(array)
  array.zip(array.reverse).to_h
end


if $0 == __FILE__ then 
  gets.to_i.times do
    n = gets.to_i
    s = gets.strip
    sym_dict = symmetric_dict(distinct_letters(s))
    s.each_char.each_with_index{|c, i| s[i]=sym_dict[c]}
    puts(s)
  end
end