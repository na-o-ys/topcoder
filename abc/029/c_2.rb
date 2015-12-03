n = gets.to_i
arr = ['a', 'b', 'c']
ans = [nil]
n.times { ans = ans.product(arr).map(&:join) }
puts ans
