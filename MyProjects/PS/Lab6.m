x = [7 7 4 5 9 9 4 12 8 1 8 7 3 13 2 1 17 7 12 5 6 2 1 13 14 10 2 4 9 11 3 5 12 6 10 7];
N=length(x);
y=mean(x);
miu0=9;
#sigma=known;
TT=(y-9)/(5/sqrt(N));
alpha=0.5;
p=1-normcdf(TT);

miu0=5.5;
#sigma=unknown;
TT=(y-9)/(std(x)/sqrt(N));
p=1-tcdf(TT,N-1);
alpha=0.1;

b)
x = [22.4 21.7 24.5 23.4 21.6 23.3 22.4 21.6 24.8 20.0];
y = [17.7 14.8 19.6 19.6 12.1 14.8 15.4 12.6 14.0 12.2];
N=length(x);

deltamiu=miux-miuy;

H0:deltamiu=0;
alpha=0.5;
x1=var(x);
y1=var(y);
teta=x1/y1;
teta0=1;
TT=
p=fcdf(TT,N-1,N-1);
