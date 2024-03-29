$DEBUG = false

def clockwise(x, d, n)
  return (x + d) % n == 0 ? n : (x + d) % n
end

def anticlockwise(x, d, n)
  return (x - d) % n == 0 ? n : (x - d) % n
end

@throws = nil
@players = nil
@dp = nil

def runBallGame(x = 0, _throw_indx = 0)
  if _throw_indx == @m
    puts("#{[x + 1, _throw_indx + 1].reverse.to_s} => set true for #{x + 1}") if $DEBUG
    @players[x] = true
    return nil
  end

  puts("@dp[#{x + 1}]=> #{@dp[x].to_s}") if $DEBUG
  if @dp[x][_throw_indx] == true
    puts("#{[x + 1, _throw_indx + 1].reverse.to_s} => dp return") if $DEBUG
    return nil
  end

  if ["0", "?"].include? @throws[_throw_indx][1] # go clockwise
    puts("#{[x + 1, _throw_indx + 1].reverse.to_s} => go clock wise") if $DEBUG
    runBallGame(
      clockwise(
        x + 1,
        @throws[_throw_indx][0],
        @n
      ) - 1,
      _throw_indx + 1
    )
  end

  if ["1", "?"].include? @throws[_throw_indx][1] # go anticlockwise
    puts("#{[x + 1, _throw_indx + 1].reverse.to_s} => go anticlockwise") if $DEBUG
    runBallGame(
      anticlockwise(
        x + 1,
        @throws[_throw_indx][0],
        @n
      ) - 1,
      _throw_indx + 1
    )
  end

  puts("#{[x + 1, _throw_indx + 1].reverse.to_s} => dp set") if $DEBUG
  @dp[x][_throw_indx] = true
  return nil
end

t = gets.to_i
t.times do
  # 2 <= n <= 1000
  # 1 <= m <= 1000
  # 1 <= x <= n
  @n, @m, x = gets.strip.split(" ").map(&:to_i)
  @players = Array.new(@n, false)
  @throws = []
  @m.times do
    @throws << gets.strip.split(" ")
  end
  @throws.map! { |x| [x[0].to_i, x[1]] }

  @dp = Array.new(@n) { Array.new(@m, false) }

  puts if $DEBUG; puts if $DEBUG
  puts("@n: #{@n}, @m: #{@m}, x: #{x}") if $DEBUG
  puts(@throws.to_s) if $DEBUG
  puts(@dp.map(&:to_s).join(" ")) if $DEBUG
  puts(@players.to_s) if $DEBUG
  runBallGame(x - 1, 0)
  puts(@players.count(true))
  puts(@players.each_with_index.collect { |v, i| v ? i + 1 : nil }.reject { |v| v == nil }.join(" "))
end
