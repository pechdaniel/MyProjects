%a)

% 0) input data
x = [46 37 39 48 47 44 35 31 44 37];
y = [35 33 31 35 34 30 27 32 31 31];

vx = var(x); % unknown variance of x
vy = var(y); % unknown variance of y

% 1) null hypothesis H0
t0 = 1; % assume var(premium) = var(regular)

% 2) observed data
t1 = vx / vy; % any relation to t0 since we do an equality test

% 3) alternate hypothesis H1
% variance of standard assembly time is DIFFERENT from variance of new assembly time

% 4) test statistic
nx = length(x);
ny = length(y);
tt = t1;
fprintf("Test statistic: tt=%4.4f\n", tt);

% 5) significance level
alpha = 0.05;
rrl = finv(alpha / 2, nx - 1, ny - 1);
rrr = finv(1 - alpha / 2, nx - 1, ny - 1);
fprintf("Rejection region: (-inf, %4.4f) U (%4.4f, inf) \n", rrl, rrr);

% 6) p-value
pl = fcdf(tt, nx - 1, ny - 1);
pr = 1 - fcdf(tt, nx - 1, ny - 1);
p = 2 * min(pl, pr);
fprintf("Significance level: %.2f, Test Statistic: %f, P-Value: p=%4.4f\n", alpha,tt, p);

% 7) conclusion
if (p < alpha)
  fprintf("Reject H0, accept H1. variance of standard assembly time is DIFFERENT from variance of new assembly time\n");
else
  fprintf("Accept H0, reject H1. variance of standard assembly time is EQUAL to variance of new assembly time\n");
end