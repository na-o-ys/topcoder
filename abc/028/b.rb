puts gets.chomp.chars.inject([0]*6) { |p_obj, c|
  p_obj[c.ord - 'A'.ord] += 1
  p_obj
}.join(' ')
