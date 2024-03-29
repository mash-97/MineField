gets.chomp.to_i.times{
  gets()
  case gets.chomp.strip.downcase
  when /^m+e+o+w+$/ then
    puts("YES")
  else
    puts("NO")
  end
}
