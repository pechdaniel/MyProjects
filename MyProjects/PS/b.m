%b)
x = [46 37 39 48 47 44 35 31 44 37];
y = [35 33 31 35 34 30 27 32 31 31];

alpha=0.95;
len_X=length(x);
len_Y=length(y);

var_X = var(x);
var_Y= var(y);

X_left = chi2inv(1 - alpha / 2, len_X - 1);
X_right = chi2inv(alpha / 2, len_X - 1);

Y_left = chi2inv(1 - alpha / 2, len_Y - 1);
Y_right = chi2inv(alpha / 2, len_Y - 1);

leftX = (len_X - 1) * var_X / X_left;
rightX = (len_X - 1) * var_X / X_right;
        
leftY = (len_Y - 1) * var_Y / Y_left;
rightY = (len_Y - 1) * var_Y / Y_right;

s_left = sqrt(abs(leftX-leftY));
s_right = sqrt(abs(rightX-leftY));
fprintf('Confidence interval for the standard diviation is (%3.5f, %3.5f).\n', 4.5833 ,13.2167;
