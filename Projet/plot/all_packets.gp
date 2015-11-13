set output 'result.png'
set terminal pngcairo background rgb 'white' size 1600,900
set xlabel 'time' tc rgb 'black'
set ylabel 'packet' tc rgb 'black'
set border lc rgb 'black'
set key tc rgb 'black'
set linetype 1 lc rgb 'black'

plot for [i=1:1000] "light_trace.txt" 1:using (i)
