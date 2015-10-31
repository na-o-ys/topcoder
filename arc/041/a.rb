x, y = gets.split.map(&:to_i)
k = gets.to_i
on = [y, k].min
puts x + on - (k - on)
