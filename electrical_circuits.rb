# PREQ --> equivalent resistor for resistors in parallel
def preq(*resistors)
    frequent_multiple = resistors.inject{|x,y|x*y}.to_f
    sum_of_nexempt = resistors.collect{|x| frequent_multiple/x}.sum 
    frequent_multiple/sum_of_nexempt
end 
# nth current in parallel combs of resistors 
def ncp(n, c, *resistors)
    fm = resistors.inject{|x,y|x*y}.to_f
    nexempt_sum = resistors.collect{|x| fm/x}.sum 
    ((fm/resistors[n-1])/nexempt_sum)*c 
end 

# SREQ --> equivalent resistor for resistors in series
def sreq(*resistors)
    resistors.sum.to_f
end 
# nth voltage in series combs of resistors 
def nvp(n, v, *resistors)
    (resistors[n-1].to_f/resistors.sum.to_f)*v
end 

