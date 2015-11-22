set output 'router4.png'
set terminal pngcairo background rgb 'white' size 1600,900
set xlabel 'time' tc rgb 'black'
set ylabel 'packet' tc rgb 'black'
set border lc rgb 'black'
set key tc rgb 'black'
set linetype 1 lc rgb 'black'

plot "traces/trace_router4.tr" using 1:2 with lines title 'Queue size' lt rgb "blue" lw 2
