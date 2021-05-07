# a program to fill a 9*9 sudoko board with appropriate numbers
puts(RUBY_VERSION)
puts([[1,2]].flatten.include?(2))
class Position
  attr_accessor :x, :y
  def initialize(x,y)
    @x = x
    @y = y
  end
end


class Suduko 
  attr_accessor :board
  
  def initialize
    @board = 9.times.collect{Array.new(9,0)}
  end
  
  def place(number, position)
    @board[position.x][position.y] = number
  end
       
	
  def getBruteForceSolution()
    board = Marshal.load(Marshal.dump(@board))
    bfSol(board)
    return board
  end
  
  def db()
    @board.each do |ar|
      puts(ar.map(&:to_s).join("\t"))
    end
  end
  
  def self.db(board)
    board.each do |ar|
      puts(ar.map(&:to_s).join("\t"))
    end
  end
  
  def dbp()
    @board.each do |ar|
      puts(ar.to_s)
    end
  end
  
  private 
  def getBlock(board, position)
    block = []
    (position.x/3...(position.x/3)+3).each do |row_index|
      row = []
      (position.y/3...(position.y/3)+3).each do |column_index|
	row << board[row_index][column_index]
      end
      block << row
    end
    return block
  end
      
  def validInBlock(board, number, position)
    block = getBlock(board, position)
    return !block.flatten.include?(number)
  end
  
  def validInRow(board, number, position)
    return !board[position.x].include?(number)
  end
  
  def validInColumn(board, number, position)
    return !board.collect{|z| z[position.y]}.include?(number)
  end
  
  def bfSol(board, x=0, y=0)
    return true if x==9
    
    return true if board[x,y] != 0 
    
    (1..9).each do |number|
      position = Position.new(x,y)
      validity = validInBlock(board, number, position)
      validity &&= validInColumn(board, number, position)
      validity &&= validInRow(board, number, position)
      puts(validity)
      if validity==true then board[x][y] = number else next end
      return true if bfSol(board, (y==8 ? x+1 : x), (y==8 ? 0 : y+1))
      board[x][y] = 0
    end
    return false
  end
end

suduko = Suduko.new()

suduko.place(2, Position.new(0,6))

suduko.place(8, Position.new(1, 1))
suduko.place(7, Position.new(1, 5))
suduko.place(9, Position.new(1, 7))

suduko.place(6, Position.new(2,0)) 
suduko.place(2, Position.new(2, 2))
suduko.place(5, Position.new(2, 6))

suduko.place(7, Position.new(3, 1))
suduko.place(6, Position.new(3, 4))

suduko.place(9, Position.new(4, 3))
suduko.place(1, Position.new(4, 5))

suduko.place(2, Position.new(5, 4))
suduko.place(4, Position.new(5, 7))

suduko.place(5, Position.new(6, 2))
suduko.place(6, Position.new(6, 6))
suduko.place(3, Position.new(6, 8))

suduko.place(9, Position.new(7, 1))
suduko.place(4, Position.new(7, 3))
suduko.place(7, Position.new(7, 7))

suduko.place(6, Position.new(8,2))

suduko.dbp()
Suduko.db(suduko.getBruteForceSolution())
