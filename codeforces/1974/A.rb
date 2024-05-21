def input_array(symbol)
  gets.strip.split(' ').map(&symbol)
end

gets.to_i.times do
  x, y = input_array(:to_i)
  td = (y/2)+(y%2)
  xdr = (y%2==1) ? ((td-1)*7 + 11) : td*7
  td = (x-xdr < 0) ? td : td + ((x-xdr)/15) + ((x-xdr)%15!=0 ? 1 : 0)
  puts(td)
end

