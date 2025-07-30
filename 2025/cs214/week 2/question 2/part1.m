    % Unit prices of the 5 products
    prices = [2.50, 1.00, 33.90, 7.00, 200.00];

    % Purchases by 6 customers (each row = one customer)
    purchases = [
        3 0 0 1 1;
        0 1 1 0 0;
        5 0 0 0 0;
        3 4 2 1 0;
        0 0 0 0 1;
        7 0 3 0 0
    ];

    % Calculate total sales per customer
    % apostrophee is used to flip row vector into col vector or vice versa
    customer_totals = purchases * prices';

    % optionally view it with customer_totals

    % Total sales of the day
    total_sales = sum(customer_totals);

    % Display the result
    fprintf('Total sales for the day: $%.2f\n', total_sales);