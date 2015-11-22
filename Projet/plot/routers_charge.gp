set output 'routers.png'
set terminal pngcairo background rgb 'white' size 1600,900
set xlabel 'Router index' tc rgb 'black'
set ylabel 'Number of packets' tc rgb 'black'
set border lc rgb 'black'
set key tc rgb 'black'
set linetype 1 lc rgb 'black'
set boxwidth 1

plot "traces/routers_traces.tr" using 1:2 with boxes title 'Packets in transition per router',\
	 "traces/routers_traces.tr" using 1:3 with boxes title 'Destructions per router' lt rgb "red" lw 3
