function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

for iter = 1:num_iters

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %
theta
    h = @(x) theta(1) +theta(2)*x;
    theta = [(theta(1) - times(alpha*(1/m),sum(bsxfun(@(xi,yi) (h(xi) - yi) ,X(:,2),y)))),
             (theta(2) - times(alpha*(1/m),sum(bsxfun(@(xi,yi) times((h(xi) - yi),xi) ,X(:,2),y))))];


    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(X, y, theta);
theta
h(2.2)
J_history(iter)
pause
end

end
