def xour(array)
  puts("#> array: #{array.to_s}")
  array.sort do |x,y|
    (((x^y)<4) and (x>y)) ? -1 : 0
  end
end


gets.to_i.times do 
  n = gets.to_i
  array = gets.strip.split(' ').map(&:to_i)
  puts(xour(array).map(&:to_s).join(' '))
end

