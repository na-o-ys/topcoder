@bs = [0,0].map{gets.split.map(&:to_i)}
@cs = [0,0,0].map{gets.split.map(&:to_i)}

@memo = {}
# turn 氏のターンで board の時のスコア
def dfs(board, turn)
  if @memo[[board, turn]]
    return @memo[[board, turn]]
  end
  # 終了条件
  finish = board.map { |row|
    row == '...'
  }.inject(&:&)
  if finish
    choku, naok = 0, 0
    [0,1].each do |row|
      [0,1,2].each do |col|
        if board[row][col] == board[row+1][col]
          choku += @bs[row][col]
        else
          naok += @bs[row][col]
        end
      end
    end
    [0,1,2].each do |row|
      [0,1].each do |col|
        if board[row][col] == board[row][col+1]
          naok += @cs[row][col]
        else
          choku += @cs[row][col]
        end
      end
    end
    return @memo[[board, turn]] = choku, naok
  end

  # 探索
  m_f = 0
  m_e = 0
  board.each_with_index do |row, r|
    row.chars.each_with_index do |cell, c|
      next if cell != '.'
      next_b = []
      board.each { |v| next_b << row.dup }
      next_b[r][c] = turn == 1 ? 'o' : 'x';
      f, e = dfs(next_b, turn == 1 ? 0 : 1)
      f, e = e, f if turn == 0
      if f > m_f
        m_f, m_e = f, e
      end
    end
  end

  m_f, m_e = m_e, m_f if turn == 0
  return @memo[[board, turn]] = m_f, m_e
end

empty_board = [
  '...',
  '...',
  '...'
]

puts dfs(empty_board, 1)
