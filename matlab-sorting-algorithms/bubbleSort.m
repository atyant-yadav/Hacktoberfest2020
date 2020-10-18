function A = bubbleSort(A)
%Input A: a row or column vector of numbers
%Input A: a row or column vector of sorted numbers


% Check input
if ~isnumeric(A) || ~isempty(find(isnan(A),1))
    error('Input should be numeric without any NaNs.')
end

[n,m] = size(A);

if n ~= 1 && m ~= 1
    error('Input should be row or column vector.')
end

% Sort
for i = 1:length(A)
    for j = i+1:length(A)
        if A(j) < A(i)
            %Swap elements
            A([i,j]) = A([j,i]);
        end
    end
end


end

