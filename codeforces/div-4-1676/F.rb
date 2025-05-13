

def main
  gets.to_i.times do 
    n, k = gets.strip.split(' ').map(&:to_i)
    a = gets.strip.split(' ').map(&:to_i)
    a = a.sort
    cmaxr_l = -1
    cmaxr_r = -1
    indx = 0
    maxr_l = -1
    maxr_r = -1
    pn = a.first
    while indx < n do 
      cn = a[indx]
      if not (cn==pn or cn==pn+1) then
        cmaxr_l = -1
        cmaxr_r = -1
      end

      cn_count = 0
      while indx < n and a[indx]==cn do 
        cn_count += 1
        indx += 1
      end
      
      if cn_count >= k then
        if cmaxr_l==-1 then
          cmaxr_l = cn
          cmaxr_r = cn
        else
          cmaxr_r = cn
        end
      else
        cmaxr_l = -1
        cmaxr_r = -1
      end

      if ((cmaxr_l!=-1 and cmaxr_r!=-1) and (cmaxr_r-cmaxr_l)>=(maxr_r-maxr_l)) then
        maxr_r = cmaxr_r
        maxr_l = cmaxr_l
      end
      pn = cn
    end

    if maxr_l==-1 or maxr_r==-1 then 
      puts("-1")
    else
      puts("#{maxr_l} #{maxr_r}")
    end
  end
end


main() 
