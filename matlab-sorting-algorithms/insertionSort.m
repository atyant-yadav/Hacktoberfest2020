function A = insertionSort(A)
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
for i = 2:length(A)
    value = A(i);
    j = i;
    %find the index j within the sorted subset (1...i-1) where element
    %A(i) belongs to
    while j > 1 && A(j-1) > value
        A(j) = A(j-1);
        j = j-1;
    end
    %subset (j,,,j-1) shifted to the right by 1
    A(j) = value;
end


end

