# g=->{gets.to_i}
# n=g[]
#v=(2..n).map{|i|puts"? 1 #{i}";[i,g[]]}.max_by(&:last).first
#puts"! #{(1..n).map{|i|next 0 if i==v;puts "? #{i} #{v}";g[]}.max}"

# (2..n).map {|i|
#   puts"? 1 #{i}"
#   [i, g[]]
# }.max_by(&:last).first
#
# (1..n).map{|i|
#   next 0 if i == v
#   puts "? #{i} #{v}"
#   g[]
# }.max

# f = ->(v){
#   (1..n).map {|w|
#     next [0,0] if v==w
#     puts"? #{v} #{w}"
#     [w, g[]]
#   }.max_by(&:last)
# }
#
# v=f[1][0]
# puts"! #{f[v][1]}"
#
# n=(g=->{gets.to_i})[]
# v=(f=->(v){(1..n).map{|w|next[0,0]if v==w
# puts"? #{v} #{w}"
# $>.flush
# [w,g[]]}.max_by(&:last)})[1][0]
# puts"! #{f[v][1]}"

# n=gets.to_i
# f=->v{(1..n).map{|w|puts"? #{v} #{w}"
# $>.dup
# [gets.to_i,w]}.max}
# puts"! #{f[f[1][1]][0]}"

a=v=n=gets.to_i
2.times{a,v=(1..n).map{|w|puts"? #{v} #{w}"
$>.dup
[gets.to_i,w]}.max}
puts"! #{a}"

v=n=gets.to_i
f=->{(1..n).map{|w|puts"? #{v} #{w}"
$>.dup
[gets.to_i,w]}.max}
f[]
puts"! #{f[][0]}"
