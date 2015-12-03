# def rec(depth)
#   if depth == 0
#     return ['']
#   end
# 
#   rec(depth - 1).map do |v|
#     ['a', 'b', 'c'].map do |chr|
#       v + chr
#     end
#   end.flatten
# end
# 
# puts rec(gets.to_i)

def rec_r(depth, arr)
  return arr if depth == 0

  rec_r(depth-1, arr.map do |v|
    ['a', 'b', 'c'].map do |chr|
      v + chr
    end
  end.flatten)
end

puts rec_r(gets.to_i, [''])
