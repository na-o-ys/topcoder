loop do
  t = gets.chomp
  break if t == "#"
  cards = 4.times.map { gets.split }.transpose
  won = 0
  score = 13.times.map { |i|
    l = cards[i][won][1]
    won = cards[i].each_with_index.max_by { |c, _|
      if [t, l].include?(c[1])
        s = ["T", "J", "Q", "K", "A"].index(c[0]) + 10 rescue c[0].to_i
        c[1] == t ? s + 20 : s
      else
        0
      end
    }[1]
  }.select(&:even?).count
  puts score > 6 ? "NS #{score-6}" : "EW #{7-score}"
end
