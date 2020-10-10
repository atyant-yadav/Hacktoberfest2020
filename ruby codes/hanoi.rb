#hanoi.rb

#The Hanoi towers problem resulted from recursion in Ruby

#a is source, b is destiny c is aux

def hanoi_move(a,b,c,n)
    if n == 1
        puts "Moving disk " + n.to_s + " from " + a + " to " + b
    else
        hanoi_move(a,c,b,n-1)
        puts "Moving disk " + n.to_s +  " from " + a + " to " + b
        hanoi_move(c,b,a,n-1)
    end
end


def main 
    n = 4
    puts "\n"
    puts "Hanoi towers problem\n"
    puts "----------------------"

    hanoi_move('A','B','C',n)
end

main