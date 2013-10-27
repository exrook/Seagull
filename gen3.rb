#!/usr/bin/env ruby

str = ''
fud = ARGV[0].to_f/2
for i in 0..ARGV[1].to_i
  for j in 0..ARGV[0].to_i
    str += (rand(2) == 0 ? '# ' : '- ')
    #puts i/Math::PI
    #puts Math::sin(i/Math::PI)*10
  end
  str += "\n"
end
puts str
