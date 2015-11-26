set output 'emit.png'
set terminal pngcairo background rgb 'white' size 1600,900
set xlabel 'Temps (s)' tc rgb 'black'
set ylabel 'Nombre de paquets' tc rgb 'black'
set border lc rgb 'black'
set key tc rgb 'black'
set linetype 1 lc rgb 'black'

plot "traces/emit_trace_router1.tr" using 1:2 with lines title '1' lt rgb "#FF00FF" lw 1,\
	"traces/emit_trace_router2.tr" using 1:2 with lines title '2' lt rgb "blue" lw 1,\
	"traces/emit_trace_router3.tr" using 1:2 with lines title '3' lt rgb "blue" lw 1,\
	"traces/emit_trace_router5.tr" using 1:2 with lines title '5' lt rgb "blue" lw 1,\
	"traces/emit_trace_router6.tr" using 1:2 with lines title '6' lt rgb "blue" lw 1,\
	"traces/emit_trace_router7.tr" using 1:2 with lines title '7' lt rgb "blue" lw 1,\
	"traces/emit_trace_router8.tr" using 1:2 with lines title '8' lt rgb "blue" lw 1,\
	"traces/emit_trace_router9.tr" using 1:2 with lines title '9' lt rgb "blue" lw 1,\
	"traces/emit_trace_router10.tr" using 1:2 with lines title '10' lt rgb "blue" lw 1,\
	"traces/emit_trace_router11.tr" using 1:2 with lines title '11' lt rgb "blue" lw 1,\
	"traces/emit_trace_router12.tr" using 1:2 with lines title '12' lt rgb "blue" lw 1,\
	"traces/emit_trace_router13.tr" using 1:2 with lines title '13' lt rgb "blue" lw 1,\
	"traces/emit_trace_router14.tr" using 1:2 with lines title '14' lt rgb "blue" lw 1,\
	"traces/emit_trace_router15.tr" using 1:2 with lines title '15' lt rgb "blue" lw 1,\
	"traces/emit_trace_router16.tr" using 1:2 with lines title '16' lt rgb "blue" lw 1,\
	"traces/emit_trace_router17.tr" using 1:2 with lines title '17' lt rgb "blue" lw 1,\
	"traces/emit_trace_router18.tr" using 1:2 with lines title '18' lt rgb "blue" lw 1,\
	"traces/emit_trace_router19.tr" using 1:2 with lines title '19' lt rgb "blue" lw 1,\
	"traces/emit_trace_router20.tr" using 1:2 with lines title '20' lt rgb "blue" lw 1,\
	"traces/emit_trace_router21.tr" using 1:2 with lines title '21' lt rgb "blue" lw 1,\
	"traces/emit_trace_router22.tr" using 1:2 with lines title '22' lt rgb "blue" lw 1,\
	"traces/emit_trace_router23.tr" using 1:2 with lines title '23' lt rgb "blue" lw 1,\
	"traces/emit_trace_router24.tr" using 1:2 with lines title '24' lt rgb "blue" lw 1,\
	"traces/emit_trace_router25.tr" using 1:2 with lines title '25' lt rgb "blue" lw 1,\
	"traces/emit_trace_router.tr" using 1:2 with lines title '26' lt rgb "blue" lw 1
