n, k = gets.split.map(&:to_f)
if n < k
  puts 0
  exit
end

# k, k, k
ans = 1
# k, k, !k
ans += 3 * (n-1)
# k, <k, >k
ans += 6 * (k-1)* (n-k)
puts ans / (n ** 3)
