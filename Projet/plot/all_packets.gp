set output 'total_packets.png'
set terminal pngcairo background rgb 'white' size 1600,900
set xlabel 'Temps (s)' tc rgb 'black'
set ylabel 'Nombre de paquets' tc rgb 'black'
set border lc rgb 'black'
set key tc rgb 'black'
set linetype 1 lc rgb 'black'

plot "traces/total_emitted.tr"  using 1:2 with lines title 'Echantillonnage du nombre de paquets émis dans le réseau toutes les 100ms' lt rgb "blue"

