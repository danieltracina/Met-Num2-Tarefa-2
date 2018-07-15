set term pdfcairo
set output "grafico_ponto_fixo.pdf"
plot "solucao.txt" w l
set term x11
