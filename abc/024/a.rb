a, b, c, k = gets.split.map(&:to_i)
s, t = gets.split.map(&:to_i)

ans = s + t >= k ? -c * (s + t) : 0
puts ans + s * a + t * b
