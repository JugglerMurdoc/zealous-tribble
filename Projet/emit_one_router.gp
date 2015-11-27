set output 'emit.png'
set terminal pngcairo background rgb 'white' size 1600,900
set xlabel 'Temps (s)' tc rgb 'black'
set ylabel 'Nombre de paquets' tc rgb 'black'
set border lc rgb 'black'
set key tc rgb 'black'
set linetype 1 lc rgb 'black'

plot "traces/emit_trace_router4.tr" using 1:2 with lines title '4' lt rgb "#FF00FF" lw 1
