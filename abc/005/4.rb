N = gets.to_i
ds = []
N.times { ds << gets.split.map(&:to_i) }
Q = gets.to_i
Q.times { ps << gets.to_i }

t = Array.new(N+1) { Array.new(N+1, 0) }
N.times do |i|
  N.times do |j|
    t[i+1][j+1] = t[i+1][j] + t[i][j+1] - t[i][j] + ds[i][j]
  end
end

ans = Array.new(N*N+1, 0)
N.times do |x0|
  N.times do |y0|
    N.times do |x1|
      N.times do |y1|
        next if (x0 > x1 or y0 > y1)

        v = t[x1+1][y1+1] - t[x1+1][y0] - t[x0][y1+1] + t[x0][y0]
        area = (x1-x0+1) * (y1-y0+1)
        ans[area] = [v, ans[area]].max
      end
    end
  end
end

(N*N).times { |i| ans[i+1] = [ans[i+1], ans[i]].max }

ps.each { |p| puts ans[p] }
