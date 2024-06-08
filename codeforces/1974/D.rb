def get_cp(chr)
  cp = [0, 0]
  case chr
  when 'N'
    cp[1] += 1
  when 'S'
    cp[1] -= 1
  when 'W'
    cp[0] += 1
  when 'E'
    cp[0] -= 1
  end
  return cp
end

def ing_backtrack2(s, csi, rob_pos, heli_pos, rh='', dp=[])
  if csi == s.length then
    if (rob_pos.first==heli_pos.first) and (rob_pos.last==heli_pos.last) then 
      if (rh.include?('R') and rh.include?('H')) then
        return rh
      else
        return nil
      end
    else
      return nil
    end
  end
  if dp[csi] == nil then
    dp[csi] = {'R' => nil, 'H' => nil}
  end

  cp = get_cp(s[csi])

  if dp[csi]['R'] == nil then
    r = ing_backtrack2(s, csi+1, rob_pos.zip(cp).collect(&:sum), heli_pos, rh+'R', dp)
    return r if r
    dp[csi]['R'] = false
  end

  if dp[csi]['H'] == nil then 
    h = ing_backtrack2(s, csi+1, rob_pos, heli_pos.zip(cp).collect(&:sum), rh+'H', dp)
    return h if h 
    dp[csi]['H'] = false
  end

  return nil
end


def ingenuity(s)
  r = ing_backtrack2(s, 0, [0, 0], [0, 0])
  if r then
    puts(r)
  else
    puts("NO")
  end
end


if $0 == __FILE__ then
  gets.to_i.times do
    n = gets.to_i
    s = gets.strip.each_char.to_a
    ingenuity(s)
  end
end
