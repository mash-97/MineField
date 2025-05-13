gets.to_i.times do
  s = gets.strip
  fp = s[0..2].split('').map(&:to_i).sum
  sp = s[3..].split('').map(&:to_i).sum
  if fp==sp then
    puts("yes")
  else
    puts("no")
  end
end