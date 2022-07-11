def square_area(x,y)
  return x*1.0*y
end

def triangle_area(x,y)
  return (x*1.0*y)/2
end



def __test__()
  y = 2
  60.times.collect{(12..3423).to_a.sample}.each do |x|
    st = nil
    # st = x.times.collect{|i| (y*1.0*x).round(4)}.sum
    # st = 
    puts("y: #{y}, x: #{x}, ssa: #{square_area(x,y).round(4)}, ta: #{triangle_area(x,y).round(4)}, st: #{st}")
  end
end

if $0 == __FILE__ then
  __test__()
end

