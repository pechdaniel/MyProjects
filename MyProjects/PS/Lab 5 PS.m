#X=[7 7 4 5 9 9 4 12 8 1 8 7 3 13 2 1 17 7 12 5 6 2 1 13 14 10 2 4 9 11 3 5 12 6 10 7]
#XM=mean(X)
#XM =  7.1111
#sigma=sqrt(var(X))
#alpha=0.05
#z=norminv(alpha/2)
#xmin=XM-z*sigma/(sqrt(length(X)))
#xmax=XM+z*sigma/sqrt(length(X))
#disp(xmin)
#disp(xmax)

X=[7 7 4 5 9 9 4 12 8 1 8 7 3 13 2 1 17 7 12 5 6 2 1 13 14 10 2 4 9 11 3 5 12 6 10 7];
XM=mean(X);
sigma=sqrt(var(X));
alpha=0.010;
z=-norminv(alpha/2);

sigma=5;
s=sqrt(var(X));

disp("A:");
xamin=XM-z*(sigma/sqrt(size(X)(1)));
xamax=XM+z*(sigma/sqrt(size(X)(1)));                                  
disp(xamin);
disp(xamax);

alpha=0.010;
N=sqrt(length(X));
t=tinv(alpha/2,N-1);
disp("B:");
xbmin=XM-t*(s/N);
xbmax=XM+t*(s/N);                                  
disp(xbmin);
disp(xbmax);

disp("C:");
disp((N-1)*s*s/chi2inv(1-alpha/2,N-1));
disp((N-1)*s*s/chi2inv(alpha/2,N-1));