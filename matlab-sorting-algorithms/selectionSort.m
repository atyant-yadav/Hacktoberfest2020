function A = selectionSort(A)
%Input A: a row or column vector of numbers
%Output A: a row or column vector of sorted numbers


% Check input
if ~isnumeric(A) || ~isempty(find(isnan(A),1))
    error('Input should be numeric without any NaNs.')
end

[n,m] = size(A);

if n ~= 1 && m ~= 1
    error('Input should be row or column vector.')
end

% Sort
for i = 1:length(A)-1
    min_i = i;
    %find the minimum element in the subset (i...n-1) and
    %swap it with A[(i)
    for j = i+1:length(A)
        if A(j) < A(min_i)
            min_i = j;
        end
    end
    %swap the minimum element in subset (i...n-1) with A(i)     
    A([i,min_i]) = A([min_i,i]);
end


end

