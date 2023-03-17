set title "Fibonacci Compare"
set xlabel "F(n)"
set ylabel "time (ns)"
set terminal png enhanced font "Verdana,12"
set output "Fib_Compare.png"
set xtics 0 ,10 ,100
set key left
set grid

plot [:][:]'output.txt' using 1 with linespoints linewidth 2 title "iterative", \
"" using 2 with linespoints linewidth 2 title "fast doubling recursive", \
"" using 3 with linespoints linewidth 2 title "fast doubling w/o clz", \
"" using 4 with linespoints linewidth 2 title "fast doubling w/ clz", \
