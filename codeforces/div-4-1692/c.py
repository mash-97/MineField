def bishop_location(chess_board):
  for i in range(1, len(chess_board)-1):
    for j in range(1, len(chess_board)-1):
      if chess_board[i][j]=='#':
        bishop_found = chess_board[i-1][j-1]=='#'
        bishop_found &= chess_board[i+1][j-1]=='#'
        bishop_found &= chess_board[i+1][j+1]=='#'
        bishop_found &= chess_board[i-1][j+1]=='#'
        if bishop_found:
          return (i+1, j+1)
  return (-1, -1)
  

if __name__=='__main__':
  for t in range(int(input().strip())):
    input()
    chess_board = []
    [chess_board.append(list(input().strip())) for _ in range(8)]
    print(' '.join(list(map(lambda x: str(x), bishop_location(chess_board)))))

