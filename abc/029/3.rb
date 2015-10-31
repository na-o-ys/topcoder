n = gets.to_i
0.upto(3**n-1) do |i|
  puts (n-1).downto(0).to_a.map{|j|'abc'[(i/(3**j))%3]}.join
end
