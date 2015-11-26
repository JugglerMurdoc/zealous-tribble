set output 'router8.png'
set terminal pngcairo background rgb 'white' size 1600,900
set xlabel 'Temps (s)' tc rgb 'black'
set ylabel 'Nombre de paquets' tc rgb 'black'
set border lc rgb 'black'
set key tc rgb 'black'
set linetype 1 lc rgb 'black'

plot "traces/trace_router8.tr" using 1:2 with lines title 'Nombre de paquets en transit' lt rgb "blue" lw 2
