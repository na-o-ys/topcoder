v = ['b']
200.times do |i|
  v << ['a',v[i],'c'].join if i % 3 == 0
  v << ['c',v[i],'a'].join if i % 3 == 1
  v << ['b',v[i],'b'].join if i % 3 == 2
end
gets
puts v.index(gets.chomp) || -1
