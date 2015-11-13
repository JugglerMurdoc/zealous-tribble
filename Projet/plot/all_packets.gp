set output 'result.png'
set terminal pngcairo background rgb 'white' size 1600,900
set xlabel 'time' tc rgb 'black'
set ylabel 'packet' tc rgb 'black'
set border lc rgb 'black'
set key tc rgb 'black'
set linetype 1 lc rgb 'black'

plot "traces/total_waiting.tr" using 1:2 with lines title 'Queue current size' lt rgb "blue" lw 2
