def clockwise(x, d, n)
  return (x + d) % n == 0 ? n : (x + d) % n
end

def anticlockwise(x, d, n)
  return (x - d) % n == 0 ? n : (x - d) % n
end

def runBallGame(x = 0, _throw_indx = 0)
  if _throw_indx == @m
    @players[x] = true
    return nil
  end

  return nil if @dp[x][_throw_indx]

  if ["0", "?"].include? @throws[_throw_indx][1] # go clockwise
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
    runBallGame(
      anticlockwise(
        x + 1,
        @throws[_throw_indx][0],
        @n
      ) - 1,
      _throw_indx + 1
    )
  end

  @dp[x][_throw_indx] = true
  return nil
end

t = gets.to_i
t.times do
  @n, @m, x = gets.strip.split(" ").map(&:to_i)
  @players = Array.new(@n, false)
  @throws = []
  @m.times do
    @throws << gets.strip.split(" ")
  end
  @throws.map! { |x| [x[0].to_i, x[1]] }
  @dp = Array.new(@n) { Array.new(@m, false) }

  runBallGame(x - 1, 0)
  puts(@players.count(true))
  puts(@players.each_with_index.collect { |v, i| v ? i + 1 : nil }.compact.join(" "))
end
