n = gets.to_i
@bs = $<.read.lines.map(&:to_i).zip([*2..n])

def kyuryo(i)
  buka_kyuryo = @bs
    .select { |b, _| b == i }
    .map    { |_, j| kyuryo(j) }

  return 1 if buka_kyuryo.empty?
  buka_kyuryo.min + buka_kyuryo.max + 1
end

puts kyuryo(1)
