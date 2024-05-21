
def ing_backtrack(s, csi, rp, hp, rh, dm)
  if csi == s.length then
    if (rp.first==hp.first) and (rp.last==hp.last) and (rh.include?('R') and rh.include?('H')) then
      return rh
    else
      return nil
    end
  end

  if not dm[csi] then 
    dm << {'R'=> false, 'H' => false}
  end

  case s[csi]
  when 'N'
    if dm[csi]['R'] then 
      return dm[csi]['R']
    else
        r = ing_backtrack(s, csi+1, [rp.first, rp.last+1], hp, rh+'R', dm)
      if r then
        dm[csi]['R'] = r
        return r 
      end
    end
    if dm[csi]['H'] then
      return dm[csi]['H']
    else
      h = ing_backtrack(s, csi+1, rp, [hp.first, hp.last+1], rh+'H', dm)
      if h then 
        dm[csi]['H'] = h
        return h
      end
      dm[csi]['H'] = false
    end
  when 'S'
    if dm[csi]['R'] then 
      return dm[csi]['R']
    else
        r = ing_backtrack(s, csi+1, [rp.first, rp.last-1], hp, rh+'R', dm)
      if r then
        dm[csi]['R'] = r
        return r 
      end
      dm[csi]['R'] = false
    end
    if dm[csi]['H'] then
      return dm[csi]['H']
    else
      h = ing_backtrack(s, csi+1, rp, [hp.first, hp.last-1], rh+'H', dm)
      if h then 
        dm[csi]['H'] = h
        return h
      end
      dm[csi]['H'] = false
    end
  when 'W'
    if dm[csi]['R'] then 
      return dm[csi]['R']
    else
        r = ing_backtrack(s, csi+1, [rp.first-1, rp.last], hp, rh+'R', dm)
      if r then
        dm[csi]['R'] = r
        return r 
      end
      dm[csi]['R'] = false
    end
    if dm[csi]['H'] then
      return dm[csi]['H']
    else
      h = ing_backtrack(s, csi+1, rp, [hp.first-1, hp.last], rh+'H', dm)
      if h then 
        dm[csi]['H'] = h
        return h
      end
      dm[csi]['H'] = false
    end
  when 'E'
    if dm[csi]['R'] then 
      return dm[csi]['R']
    else
        r = ing_backtrack(s, csi+1, [rp.first+1, rp.last], hp, rh+'R', dm)
      if r then
        dm[csi]['R'] = r
        return r 
      end
      dm[csi]['R'] = false
    end
    if dm[csi]['H'] then
      return dm[csi]['H']
    else
      h = ing_backtrack(s, csi+1, rp, [hp.first+1, hp.last], rh+'H', dm)
      if h then 
        dm[csi]['H'] = h
        return h
      end
      dm[csi]['H'] = false
    end
  end
  return nil
end

def ingenuity(s)
  r = ing_backtrack(s, 0, [0, 0], [0, 0], '', [])
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
