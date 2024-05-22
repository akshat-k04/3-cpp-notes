\documentclass{article}
\usepackage{geometry}

\begin{document}

% \begin{table}[ht]
\centering
\caption{RSICD}
\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|}
\hline
\multicolumn{2}{|c|}{} & BLEU-1 & BLEU-2 & BLEU-3 & BLEU-4 & METEOR & ROUGE-L & CIDEr & NGM \\
\hline
\multirow{RESNET} & Greedy & 0.6407 & 0.4676 & 0.3608 & 0.2878 & 0.2574 & 0.4745 & 0.799 &  \\
\cline{2-10}
& Beam & 0.6121 & 0.4409 & 0.3385 & 0.2708 & 0.2579 & 0.4609 & 0.7594 &  \\
\hline
\multirow{DENSENET} & Greedy & 0.6216 & 0.446 & 0.3419 & 0.2719 & 0.2459 & 0.4639 & 0.7278 &  \\
\cline{2-10}
& Beam & 0.6021 & 0.4283 & 0.325 & 0.2574 & 0.2526 & 0.4469 & 0.6975 & \\
\hline
\multirow{ALEXNET} & Greedy & 0.6089 & 0.4287 & 0.323 & 0.2539 & 0.2378 & 0.4475 & 0.667 & \\
\cline{2-10}
& Beam & 0.5861 & 0.4089 & 0.3093 & 0.2446 & 0.2463 & 0.437 & 0.6489 &  \\
\hline
\multirow{GOOGLENET} & Greedy & 0.6213 & 0.4427 & 0.336 & 0.2653 & 0.2433 & 0.4582 & 0.7042 &  \\
\cline{2-10}
& Beam & 0.5943 & 0.4161 & 0.3115 & 0.2435 & 0.2534 & 0.448 & 0.6822 & \\
\hline
\multirow{VGGNET} & Greedy & 0.6015 & 0.425 & 0.3208 & 0.2505 & 0.2311 & 0.446 & 0.645 &  \\
\cline{2-10}
& Beam & 0.5899 & 0.4164 & 0.3121 & 0.244 & 0.2462 & 0.4374 & 0.6144 & \\
\hline
\multirow{INCEPTIONNET} & Greedy & 0.5979 & 0.4248 & 0.3245 & 0.2588 & 0.2372 & 0.4475 & 0.6383 &  \\
\cline{2-10}
& Beam & 0.5753 & 0.4054 & 0.3101 & 0.249 & 0.2393 & 0.43 & 0.6303 &  \\
\hline
\multirow{MOBILENET} & Greedy & 0.6348 & 0.4599 & 0.356 & 0.286 & 0.255 & 0.468 & 0.759 & \\
\cline{2-10}
& Beam & 0.6255 & 0.4542 & 0.3548 & 0.2883 & 0.2646 & 0.4671 & 0.7567 &  \\
\hline
\multirow{EFFICIENTNET} & Greedy & 0.6357 & 0.4605 & 0.3561 & 0.2871 & 0.2612 & 0.4774 & 0.7888 &  \\
\cline{2-10}
& Beam & 0.6006 & 0.4317 & 0.3319 & 0.2675 & 0.2652 & 0.4548 & 0.7422 & \\
\hline
\end{tabular}
\end{table}

\end{document}
