function SinSamplesGenerator
clear all;
close all;
a = 0.3;
N = 20; % number of samples in period
N_PERIODS = 20; % number of sinus periods to observe
A = 127; % sin amplitude
DC = 127; % sin DC value
N_TOTAL = N_PERIODS * N; % total samples to observe
t = N_PERIODS * linspace(0, N_TOTAL, N_TOTAL+1) / N_TOTAL; % time vector
t(end) = [];
s = DC + (A * (exp(-a*t).* sin(2*pi*t)));
plot(s,'-o', 'LineWidth', 3, 'Color', [0 0 0]);
set(gca,'XLim', [0 N_TOTAL], 'YLim', [DC-A DC+A]);
grid on;
fid = fopen('sinsamples_Mode1(a=0.3).txt', 'w');
fprintf(fid,'const uint8 Samples[] = { \n');
fprintf(fid,' %d,',round(s(1:end-1)));
fprintf(fid,' %d\n',round(s(end)));
fprintf(fid,' }; \n');
fclose(fid);