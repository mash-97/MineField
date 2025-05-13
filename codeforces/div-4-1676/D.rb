def lr_sum(xn, xm, ln, lm, board)
  sum = 0
  while xn<ln and xm<lm do 
    sum += board[xn][xm]
    xn += 1
    xm += 1
  end
  return sum
end

def lr_place_sum(sum, xn, xm, ln, lm, ltr_board)
  while xn<ln and xm<lm do
    ltr_board[xn][xm] = sum
    xn += 1
    xm += 1
  end
end

def rl_sum(xn, xm, ln, lm, board)
  sum = 0
  while xn<ln and xm>=0 do 
    sum += board[xn][xm]
    xn += 1
    xm -= 1
  end
  return sum
end

def rl_place_sum(sum, xn, xm, ln, lm, rtl_board)
  while xn<ln and xm>=0 do
    rtl_board[xn][xm] = sum
    xn += 1
    xm -= 1
  end
end

def ltr(board)
  ln = board.size
  lm = board.first.size
  ltr_board = Array.new(ln){Array.new(lm){0}}
  
  # upper triangle
  (1..lm).each do |xm|
    sum = lr_sum(0, xm, ln, lm, board)
    lr_place_sum(sum, 0, xm, ln, lm, ltr_board)
  end

  # middle diagonal
  x = lr_sum(0, 0, ln, lm, board)
  lr_place_sum(x, 0, 0, ln, lm, ltr_board)

  # lower triangle
  (1..ln).each do |xn|
    sum = lr_sum(xn, 0, ln, lm, board)
    lr_place_sum(sum, xn, 0, ln, lm, ltr_board)
  end

  # ltr_board.each do |xltr|
  #   puts(xltr.to_s)
  # end;puts
  return ltr_board
end

def rtl(board)
  ln = board.size
  lm = board.first.size
  rtl_board = Array.new(ln){Array.new(lm){0}}
  
  # upper triangle
  (0...lm-1).each do |xm|
    sum = rl_sum(0, xm, ln, lm, board)
    rl_place_sum(sum, 0, xm, ln, lm, rtl_board)
  end

  # middle diagonal
  x = rl_sum(0, lm-1, ln, lm, board)
  rl_place_sum(x, 0, lm-1, ln, lm, rtl_board)

  # lower triangle
  (1..ln).each do |xn|
    sum = rl_sum(xn, lm-1, ln, lm, board)
    rl_place_sum(sum, xn, lm-1, ln, lm, rtl_board)
  end

  # rtl_board.each do |xrtl|
  #   puts(xrtl.to_s)
  # end;puts()
  return rtl_board
end

def get_add_matrix(amatrix, bmatrix, matrix)
  matrx = Array.new(amatrix.size){Array.new(amatrix.first.size){0}}
  i = 0
  while i<amatrix.size do 
    j = 0
    while j<amatrix.first.size do 
      matrx[i][j] += amatrix[i][j]+bmatrix[i][j]-(1*matrix[i][j])
      j+=1
    end
    i+=1
  end
  return matrx
end


def main
  gets.to_i.times do 
    n, m = gets.strip.split(' ').map(&:to_i)
    matrix = []
    n.times do 
      matrix << gets.strip.split(' ').map(&:to_i)
    end

    puts(get_add_matrix(ltr(matrix), rtl(matrix), matrix).flatten.max)
  end
end

if $0==__FILE__ then
  main()
end
