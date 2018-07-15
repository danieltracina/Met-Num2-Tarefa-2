set term pdfcairo
set output "grafico_ponto_fixo.pdf"
set title "Solução de cos x - x = 0"
set ylabel "Valores de x" 
set xlabel "Número de iterações" 
plot "solucao.txt" w l
set term x11

