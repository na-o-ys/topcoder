a, b, c = STDIN.gets.split(" ").map(&:to_i)
if c == a+b and c == a-b
  puts '?'
elsif c == a+b
  puts '+'
elsif c == a-b
  puts '-'
else
  puts '!'
end
