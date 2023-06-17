
def getBats(label, num, probability)
  return num.times.collect do 
    if Random.new.random_number <= probability then
      (label.downcase()+'d').to_sym
    else
      label.downcase().to_sym
    end
  end
end

def simulate(runtime)
  a = getBats('a', 35, 0.15)
  b = getBats('b', 67, 0.19)
  t = a+b
  num_optimal_case = 0
  total_event_case = 0
  ext_case = 0
  runtime.times do
    while true do
      ext_case += 1
      temp = t.sample
      if(temp.to_s.match(/d/)) then
        total_event_case += 1
        if(temp == :bd) then
          num_optimal_case += 1
        end
        break
      end
    end
  end
  puts("#{(num_optimal_case.to_f/total_event_case).round(3)}: num_optimal_case: #{num_optimal_case}, total_event_case: #{total_event_case}, ext_case: #{ext_case}")
  return [(num_optimal_case.to_f/total_event_case).round(3), ext_case, total_event_case, num_optimal_case]
end


if $0==__FILE__ then
  probs = []
  ext_cases = []
  event_cases = []
  optimal_cases = []
  tries = ARGV[0].to_i
  tries.times do
    res = simulate(rand(1..500))
    probs << res[0]
    ext_cases << res[1]
    event_cases << res[2]
    optimal_cases << res[3]
  end
  puts()
  puts("total tries: #{tries}")
  puts("average probability: #{(probs.sum.to_f/probs.length).round(3)}")
  puts("optimal_cases / event_cases: #{(optimal_cases.sum.to_f/event_cases.sum.to_f).round(3)}")
  puts("event_cases / ext_cases: #{(event_cases.sum.to_f/ext_cases.sum.to_f).round(3)}")
  puts("optimal_cases / ext_cases: #{(optimal_cases.sum.to_f/ext_cases.sum.to_f).round(3)}")
end

