n = gets.to_i
(3 ** n).times do |i|
  n.times do |j|
    print ['a', 'b', 'c'][i / (3 ** (n - j - 1)) % 3]
  end
  puts
end
