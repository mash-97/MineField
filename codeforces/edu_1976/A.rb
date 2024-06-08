gets.to_i.times do
  gets
  s = gets.strip
  dl = ('0'..'9').to_a + ('a'..'z').to_a
  dli = 0
  si = 0
  while si<s.length and dli < dl.length do
    while dli < dl.length and dl[dli]<s[si] do
      dli += 1
    end
    if dli < dl.length and dl[dli]==s[si] then
      si += 1
    else
      break
    end
  end

  if si==s.length then
    puts("Yes")
  else
    puts("No")
  end
end
