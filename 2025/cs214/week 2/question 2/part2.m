% Define the range of x values
x = -10:0.1:10;     % x goes from -10 to 10 in steps of 0.1

% Define y = x^2
y = x.^2;           % Use .^ for element-wise squaring

% Plot the graph
plot(x, y)

% Add labels and title
xlabel('x')
ylabel('y = x^2')
title('Plot of y = x^2')
grid on               % Adds grid lines for clarity

