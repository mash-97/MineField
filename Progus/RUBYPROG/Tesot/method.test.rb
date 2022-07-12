def o(m)
   m.each{|x|
       if(not (/(kill)|(exit)/ =~ x.to_s)) then
           begin
             puts("For #{x.to_s}:")
             puts send(x).to_s
           rescue
             puts("Couldn't operate: #{$!}")
           end
       end
       puts
   }
end

o methods
