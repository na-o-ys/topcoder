gets
p gets.split.map(&:to_i).group_by{|n|n/=2 while n%2==0;n}.size
