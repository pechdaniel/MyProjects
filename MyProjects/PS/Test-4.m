% 4. Nickel powders are used in coatings used to shield electronic equipment. 
% A random sample is selected, and the sizes of nickel particles in each coating 
% are recorded ( they are assumed to be approximately normally distributed)

X = [3.26 1.89 2.42 2.03 3.07 2.95 1.39 3.06 2.46 3.35 1.56 1.79 1.76 3.82 2.42 2.96];

% A) at the 5% significance level, on average, do these nickel particles seem to be smaller than 3?

% variance is unknow, we have only one data set so
sigma = std(X);

% null hypothesis H0, we assume nickel particles are, on average, 3 in size
H0 = 3; 

% observed data
H1 = mean(X); % lower than H0 since we do a left test

% alternate hypothesis H1
% average size of nickel particles is lower than 3

% test statistic
len_X = length(X);
test_st = (H1 - H0) / (sigma / sqrt(len_X));
fprintf("Test statistic: tt=%4.4f\n", test_st);

% significance level
alpha = 0.05;
rreg = tinv(alpha, len_X - 1);
fprintf("Rejection region: (%4.4f, inf)\n", rreg);

% p - value
p_value = tcdf(test_st, len_X - 1);
fprintf("Significance level: %.2f, P-Value: p=%4.4f\n", alpha, p_value);

% conclusion
if (p_value < alpha)
  fprintf("Reject H0, accept H1. average size of nickel particles is lower than 3\n");
else
  fprintf("Accept H0, reject H1. average size of nickel particles is NOT lower than 3\n");
end

% B) Find a 99% confidence interval for the standard deviation of the size of nickel particles

var_X = var(X);

X_left = chi2inv(1 - alpha / 2, len_X - 1);
X_right = chi2inv(alpha / 2, len_X - 1);

left = (len_X - 1) * var_X / X_left;
right = (len_X - 1) * var_X / X_right;

s_left = sqrt(left);
s_right = sqrt(right);
fprintf('Confidence interval for the standard diviation is (%3.5f, %3.5f).\n', sqrt(s_left) ,sqrt(s_right));