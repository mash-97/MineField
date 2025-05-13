
def fall_down(cn, grid)
  stones = 0
  prev_break = -1
  grid.size.times do 
    |ri|
    if grid[ri][cn]=='*' then
      stones += 1
      if ri==grid.size-1 then
        ((prev_break+1)..(ri-stones)).each{|i| grid[i][cn]='.'}
        ((ri-stones+1)..ri).each{|i| grid[i][cn]='*'}
      end
    elsif grid[ri][cn]=='o' then
      ((prev_break+1)...(ri-stones)).each{|i| grid[i][cn]='.'}
      ((ri-stones)...ri).each{|i| grid[i][cn]='*'}
      stones = 0
      prev_break = ri
    elsif ri==grid.size-1 then
      ((prev_break+1)..(ri-stones)).each{|i| grid[i][cn]='.'}
      ((ri-stones+1)..ri).each{|i| grid[i][cn]='*'}
    end
  end
end

def main()
  gets.to_i.times do 
    n, m = gets.strip.split(' ').map(&:to_i)
    grid = []
    n.times do 
      grid << gets.strip()
    end
    m.times do 
      |cn| 
      fall_down(cn, grid) 
    end

    grid.each do |row|
      puts(row)
    end
    puts
  end
end


if $0==__FILE__ then
  main()
end

