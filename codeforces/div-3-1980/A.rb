gets.to_i.times do
  n, m = gets.strip.split(' ').map(&:to_i)
  a = gets.strip
  a_hash = ('A'..'G').to_a
  a_hash = a_hash.zip(a_hash.size.times.collect{0}).to_h
  a.each_char{|char| a_hash[char] += 1}
  # puts(a_hash.to_s)

  ans = 0
  a_hash.each do |char, count|
    ans += (m-count)>0 ? m-count : 0
  end

  puts(ans)
end
