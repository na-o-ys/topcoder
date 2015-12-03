n = gets.to_i
ans = [""]
n.times do
  ans = ans.map do |v|
    ['a', 'b', 'c'].map do |chr|
      v + chr
    end
  end.flatten
end

puts ans
