a, b = STDIN.gets.chomp
            .split.map(&:to_i)

def v(num, i)
  i.times { num /= 10 }
  num % 10
end

def solve(num)
  dp = Hash.new { |h, k| h[k] = {} }
  dp[0][0] = dp[0][1] = 1
  digits = num.to_s.length

  digits.times do |i|
    dp[i+1][0] = dp[i+1][1] = 0

    9.times do |j|
      next if j == 4 || j == 9
      dp[i+1][0] += dp[i][0]
    end

    d = v(num, i)
    (0..d).each do |j|
      next if j == 4 || j == 9
      dp[i+1][1] += dp[i][j == d ? 1 : 0]
    end
  end

  num - (dp[digits][1]) + 1
end

puts solve(b) - solve(a-1)
